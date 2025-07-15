#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define _shift(xs, xs_sz) (NULL, (xs_sz)--, *(xs)++)
#define shift(argc, argv) _shift(*argv, *argc)

int copy_to_clipboard(char* text) {
#ifdef _WIN32
    // Windows implementation (as shown above)
    if (!OpenClipboard(NULL)) return 0;
    if (!EmptyClipboard()) { CloseClipboard(); return 0; }

    size_t len = strlen(text) + 1;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
    if (!hMem) { CloseClipboard(); return 0; }

    memcpy(GlobalLock(hMem), text, len);
    GlobalUnlock(hMem);

    if (!SetClipboardData(CF_TEXT, hMem)) {
        GlobalFree(hMem);
        CloseClipboard();
        return 0;
    }

    CloseClipboard();
    return 1;
#elif __APPLE__
    // macOS
    FILE* pipe = popen("pbcopy", "w");
    if (!pipe) return 0;
    fprintf(pipe, "%s", text);
    return pclose(pipe) == 0;
#else
    // Linux/Unix
    FILE* pipe = popen("xclip -selection clipboard", "w");
    if (!pipe) return 0;
    fprintf(pipe, "%s", text);
    return pclose(pipe) == 0;
#endif
}

size_t get_file_size(FILE* file_ptr) {
	size_t file_size;

	fseek(file_ptr, 0L, SEEK_END);
	if((file_size = ftell(file_ptr)) == (size_t)-1) {
		fclose(file_ptr);
		fprintf(stderr, "Error: Could not read file size\n");
		return -1;
	}

	fseek(file_ptr, 0L, SEEK_SET);
	return file_size;
}

int main(int argc, char** argv) {

	const char* prog_name = shift(&argc, &argv);
	const char* file_name = shift(&argc, &argv);

	if(file_name == NULL) {
		fprintf(stderr, "Usage: %s <textfile>\n", prog_name);
		return EXIT_FAILURE;
	}

	FILE* file_ptr = fopen(file_name, "r");
	if(file_ptr == NULL) {
		fprintf(stderr, "Could not open %s\n", file_name);
		return EXIT_FAILURE;
	}

	size_t file_size;
	if((file_size = get_file_size(file_ptr)) == (size_t)-1) {
		return EXIT_FAILURE; //An error has already been printed and the file ptr closed by the get_file size function.
	}

	// Handle empty files
	if(file_size == 0) {
		fprintf(stdout, "File is empty nothing to copy!\n");
		return EXIT_SUCCESS;
	}

	char* file_data = (char*)malloc(sizeof(char) * file_size);

	if(fread(file_data, 1, file_size, file_ptr) != file_size) {
		fprintf(stderr, "Error reading %s\n", file_name);
		return EXIT_FAILURE;
	}

	int code = 0;
	if((code = copy_to_clipboard(file_data)) == 0) {
		fprintf(stderr, "Error writing clipboard data: %i\n", code);
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
