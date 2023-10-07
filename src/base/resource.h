
#ifndef BASE_RESOURCE_H_
#define BASE_RESOURCE_H_

#include "base.h"

typedef enum {
    BASE_RESOURCE_LOCATION_INVALID = -1,
    BASE_RESOURCE_LOCATION_DATA, // read-only: game data location
    BASE_RESOURCE_LOCATION_USER, // read-write: location per game
    BASE_RESOURCE_LOCATION_GLOBAL, // read-write: global location shared by all games
    BASE_RESOURCE_LOCATION_FILE, // read-write: file location pointer
    BASE_RESOURCE_LOCATION_HTTP, // read-only: downloads using curl, may not add
} base_resource_location_t;

typedef enum {
    BASE_RESOURCE_TYPE_INVALID = -1,
    BASE_RESOURCE_TYPE_MESH,
    BASE_RESOURCE_TYPE_TEXTURE2D,
} base_resource_type_t;

#define BASE_RESOURCE_HEADER base_resource_type_t type; \
    int rc; \
    char *data

typedef struct {
    BASE_RESOURCE_HEADER;
} base_resource_t;

base_resource_location_t base_resource_location_guess(const char *path);
base_resource_type_t base_resource_type_guess(const char *path);
base_resource_t *base_resource_load(const char *path);
base_resource_t *base_resource_ref(base_resource_t *res);
char *base_resource_load_data(const char *path);
int base_resource_deref(base_resource_t *res);

#endif // BASE_RESOURCE_H_
