
#include "resource.h"

#include <stdlib.h>

const struct location_name {
    base_resource_location_t location;
    const char *str;
} location_names[] = {
    {BASE_RESOURCE_LOCATION_DATA, "data"},
    {BASE_RESOURCE_LOCATION_USER, "user"},
    {BASE_RESOURCE_LOCATION_GLOBAL, "global"},
    {BASE_RESOURCE_LOCATION_FILE, "file"},
    {BASE_RESOURCE_LOCATION_HTTP, "http"},
    {BASE_RESOURCE_LOCATION_INVALID, NULL},
};

base_resource_location_t base_resource_location_guess(const char *path) {
    for (const struct location_name *n = location_names; n->str != NULL; n++) {

    }
}

base_resource_type_t base_resource_type_guess(const char *path) {
    
}

static base_resource_t *base_resource_load_mesh(const char *path) {

}

static base_resource_t *base_resource_load_from_type(const char *path, base_resource_type_t type) {
    switch (type) {
    case BASE_RESOURCE_TYPE_MESH:
        return base_resource_load_mesh(path);
    case BASE_RESOURCE_TYPE_TEXTURE2D:

    default:
        return NULL;
    }
}

base_resource_t *base_resource_load(const char *path) {
    base_resource_type_t type = base_resource_type_guess(path);

    if (type == BASE_RESOURCE_LOCATION_INVALID)
        return NULL;
    
    base_resource_t *res = base_resource_load_from_type(path, type);
    if (res == NULL)
        return NULL;

    res->data = NULL;
    res->type = type;
    res->rc = 1;
    return res;
}

char *base_resource_load_data(const char *path) {
    
}

int base_resource_deref(base_resource_t *res) {
    res->rc--;
    if (res->rc < 0) {
        if (res->data)
            free(res->data);
        free(res);
        return 1;
    }
    return 0;
}

base_resource_t *base_resource_ref(base_resource_t *res) {
    res->rc++;
    return res;
}

