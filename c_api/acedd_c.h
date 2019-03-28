#ifdef __cplusplus
extern "C" {
#endif

/// CEDD descriptor length (number of bins in total)
#define ACEDD_DESC_LENGTH 144

/** Extract the CEDD descriptor from an image in a file.
 * 
 * CEDD grid size defaults to 40.
 * 
 * @param filename the file system path to the image
 * @param desc pointer to an array of 144 bytes for storing the output
 * 
 * @return 0 on success, some other number if an error occurred
 */
int acedd_extract(const char* filename, unsigned char* desc);

/** Extract the CEDD descriptor from an image in a file.
 * 
 * @param filename the file system path to the image
 * @param desc pointer to an array of 144 bytes for storing the output
 * @param grid_size CEDD property for the size of the grid
 * 
 * @return 0 on success, some other number if an error occurred
 */
int acedd_extract_with_grid_size(const char* filename, unsigned char* desc, int grid_size);

#ifdef __cplusplus
}
#endif
