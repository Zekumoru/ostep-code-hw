#ifndef UTILS_H
#define UTILS_H

/**
 * \brief Duplicates a given string.
 * \param str The string to duplicate.
 * \return The duplicated string.
 * \warning It is up to the caller to free this string from memory.
 */
char *strdup(const char str[]);

#endif // UTILS_H
