#include "client.h"
#include "device.h"
#include "utility.h"

m2x_response m2x_device_catalog(m2x_context *ctx, const char *query)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_query_path(ctx, "/devices/catalog", query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_list(m2x_context *ctx, const char *query)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_query_path(ctx, "/devices", query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_search(m2x_context *ctx, const char *query)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_query_path(ctx, "/devices/search", query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_tags(m2x_context *ctx)
{
  int status;
  char *out = NULL;

  status = m2x_client_get(ctx, "/devices/tags", &out);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_create(m2x_context *ctx, const char *data)
{
  int status;
  char *out = NULL;

  status = m2x_client_post(ctx, "/devices", data, &out);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_update(m2x_context *ctx, const char *device_id,
                               const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s", device_id);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_view(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_location(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/location", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_location_update(m2x_context *ctx, const char *device_id,
                                        const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/location", device_id);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_streams(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_create(m2x_context *ctx, const char *device_id,
                                      const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s", device_id, stream_name);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_value_update(m2x_context *ctx, const char *device_id,
                                            const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/value",
                                           device_id, stream_name);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_view(m2x_context *ctx, const char *device_id,
                                    const char *stream_name)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s", device_id, stream_name);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_list_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *query)
{
  int status;
  char *path, *path2, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/values.json", device_id, stream_name);
  path2 = m2x_internal_create_query_path(ctx, path, query);
  m2x_free(path);

  status = m2x_client_get(ctx, path2, &out);
  m2x_free(path2);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_sampling(m2x_context *ctx, const char *device_id,
                                        const char *stream_name, const char *query)
{
  int status;
  char *path, *path2, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/sampling.json", device_id, stream_name);
  path2 = m2x_internal_create_query_path(ctx, path, query);
  m2x_free(path);

  status = m2x_client_get(ctx, path2, &out);
  m2x_free(path2);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_stats(m2x_context *ctx, const char *device_id,
                                     const char *stream_name, const char *query)
{
  int status;
  char *path, *path2, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/stats", device_id, stream_name);
  path2 = m2x_internal_create_query_path(ctx, path, query);
  m2x_free(path);

  status = m2x_client_get(ctx, path2, &out);
  m2x_free(path2);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_post_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/values", device_id, stream_name);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_delete_values(m2x_context *ctx, const char *device_id,
                                             const char *stream_name, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s/values", device_id, stream_name);

  status = m2x_client_delete(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_stream_delete(m2x_context *ctx, const char *device_id,
                                      const char *stream_name)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/streams/%s", device_id, stream_name);

  status = m2x_client_delete(ctx, path, NULL, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_post_updates(m2x_context *ctx, const char *device_id,
                                     const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/updates", device_id);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_view_log(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/log", device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_delete(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s", device_id);

  status = m2x_client_delete(ctx, path, NULL, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_search_values(m2x_context *ctx, const char *device_id,
                                      const char *query)
{
  int status;
  char *base_path, *path, *out = NULL;

  base_path = m2x_internal_create_format_string(ctx, "/devices/%s/values/search.json", device_id);
  path = m2x_internal_create_query_path(ctx, base_path, query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  m2x_free(base_path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_post_update(m2x_context *ctx, const char *device_id,
                                    const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/update", device_id);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_command_list(m2x_context *ctx, const char *device_id,
                                     const char *query)
{
  int status;
  char *base_path, *path, *out = NULL;

  base_path = m2x_internal_create_format_string(ctx, "/devices/%s/commands",
                                                device_id);
  path = m2x_internal_create_query_path(ctx, base_path, query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  m2x_free(base_path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_command_view(m2x_context *ctx, const char *device_id,
                                     const char *command_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/commands/%s",
                                           device_id, command_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_command_process(m2x_context *ctx, const char *device_id,
                                        const char *command_id, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/commands/%s/process",
                                           device_id, command_id);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_command_reject(m2x_context *ctx, const char *device_id,
                                       const char *command_id, const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/commands/%s/reject",
                                           device_id, command_id);

  status = m2x_client_post(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_location_history(m2x_context *ctx, const char *device_id,
                                         const char *query)
{
  int status;
  char *base_path, *path, *out = NULL;

  base_path = m2x_internal_create_format_string(ctx, "/devices/%s/location/waypoints",
                                                device_id);
  path = m2x_internal_create_query_path(ctx, base_path, query);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  m2x_free(base_path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_delete_location_history(m2x_context *ctx, const char *device_id,
                                         const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/location/waypoints", device_id);

  status = m2x_client_delete(ctx, path, data, &out);
  m2x_free(path);

  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_metadata(m2x_context *ctx, const char *device_id)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/metadata",
                                           device_id);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_metadata_update(m2x_context *ctx,
                                        const char *device_id,
                                        const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/metadata",
                                           device_id);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_metadata_field(m2x_context *ctx,
                                       const char *device_id,
                                       const char *field)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/metadata/%s",
                                           device_id, field);

  status = m2x_client_get(ctx, path, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_metadata_field_update(m2x_context *ctx,
                                              const char *device_id,
                                              const char *field,
                                              const char *data)
{
  int status;
  char *path, *out = NULL;

  path = m2x_internal_create_format_string(ctx, "/devices/%s/metadata/%s",
                                           device_id, field);

  status = m2x_client_put(ctx, path, data, &out);
  m2x_free(path);
  return m2x_make_response(ctx, status, out);
}

m2x_response m2x_device_export_values(m2x_context *ctx, const char *device_id,
                                      const char *query)
{
  int status;
  char *base_path, *path, *out = NULL, *location = NULL;

  base_path = m2x_internal_create_format_string(ctx, "/devices/%s/values/export.csv",
                                                device_id);
  path = m2x_internal_create_query_path(ctx, base_path, query);

  status = m2x_client_get_with_location(ctx, path, &out, &location);
  m2x_free(path);
  m2x_free(base_path);
  return m2x_make_response_with_location(ctx, status, out, location);
}
