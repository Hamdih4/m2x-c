#ifndef M2X_DEVICE_H
#define M2X_DEVICE_H

#include "response.h"

#if defined(__cplusplus)
extern "C" {
#endif

m2x_response m2x_device_catalog(m2x_context *ctx, const char *query);
m2x_response m2x_device_list(m2x_context *ctx, const char *query);
m2x_response m2x_device_search(m2x_context *ctx, const char *query);
m2x_response m2x_device_tags(m2x_context *ctx);
m2x_response m2x_device_create(m2x_context *ctx, const char *data);
m2x_response m2x_device_update(m2x_context *ctx, const char *device_id,
                               const char *data);
m2x_response m2x_device_view(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_view_log(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_delete(m2x_context *ctx, const char *device_id);
/* Link: https://m2x.att.com/developer/documentation/v2/device#Export-Values-from-all-Data-Streams-of-a-Device */
m2x_response m2x_device_export_values(m2x_context *ctx, const char *device_id,
                                      const char *query);

m2x_response m2x_device_location(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_location_update(m2x_context *ctx, const char *device_id,
                                        const char *data);
/* Link: https://m2x.att.com/developer/documentation/v2/device#Read-Device-Location-History */
m2x_response m2x_device_location_history(m2x_context *ctx, const char *device_id,
                                         const char *query);
m2x_response m2x_device_delete_location_history(m2x_context *ctx, const char *device_id,
					const char *data);
m2x_response m2x_device_search_values(m2x_context *ctx, const char *device_id,
                                      const char *query);

m2x_response m2x_device_streams(m2x_context *ctx, const char *device_id);
m2x_response m2x_device_stream_create(m2x_context *ctx, const char *device_id,
                                      const char *stream_name, const char *data);
#define m2x_device_stream_update m2x_device_stream_create
m2x_response m2x_device_stream_value_update(m2x_context *ctx, const char *device_id,
                                            const char *stream_name, const char *data);
m2x_response m2x_device_stream_view(m2x_context *ctx, const char *device_id,
                                    const char *stream_name);
m2x_response m2x_device_stream_list_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *query);
m2x_response m2x_device_stream_sampling(m2x_context *ctx, const char *device_id,
                                        const char *stream_name, const char *query);
m2x_response m2x_device_stream_stats(m2x_context *ctx, const char *device_id,
                                     const char *stream_name, const char *query);
m2x_response m2x_device_stream_post_values(m2x_context *ctx, const char *device_id,
                                           const char *stream_name, const char *data);
m2x_response m2x_device_stream_delete_values(m2x_context *ctx, const char *device_id,
                                             const char *stream_name, const char *data);
m2x_response m2x_device_stream_delete(m2x_context *ctx, const char *device_id,
                                      const char *stream_name);
m2x_response m2x_device_post_updates(m2x_context *ctx, const char *device_id,
                                     const char *data);
/*
 * Notice this refers to Post Device Update (Single Values To Multiple Streams)
 * API, which is different from the one above
 *
 * For more details, please check this link:
 * https://m2x.att.com/developer/documentation/v2/device#Post-Device-Update--Single-Values-to-Multiple-Streams-
 */
m2x_response m2x_device_post_update(m2x_context *ctx, const char *device_id,
                                    const char *data);

/* Link: https://m2x.att.com/developer/documentation/v2/commands#Device-s-List-of-Received-Commands */
m2x_response m2x_device_command_list(m2x_context *ctx, const char *device_id,
                                     const char *query);
/* Link: https://m2x.att.com/developer/documentation/v2/commands#Device-s-View-of-Command-Details */
m2x_response m2x_device_command_view(m2x_context *ctx, const char *device_id,
                                     const char *command_id);
/* Link: https://m2x.att.com/developer/documentation/v2/commands#Device-Marks-a-Command-as-Processed */
m2x_response m2x_device_command_process(m2x_context *ctx, const char *device_id,
                                        const char *command_id, const char *data);
/* Link: https://m2x.att.com/developer/documentation/v2/commands#Device-Marks-a-Command-as-Rejected */
m2x_response m2x_device_command_reject(m2x_context *ctx, const char *device_id,
                                       const char *command_id, const char *data);

/* Link: https://m2x.att.com/developer/documentation/v2/device#Read-Device-Metadata */
m2x_response m2x_device_metadata(m2x_context *ctx, const char *device_id);
/* Link: https://m2x.att.com/developer/documentation/v2/device#Update-Device-Metadata */
m2x_response m2x_device_metadata_update(m2x_context *ctx,
                                        const char *device_id,
                                        const char *data);
/* Link: https://m2x.att.com/developer/documentation/v2/device#Read-Device-Metadata-Field */
m2x_response m2x_device_metadata_field(m2x_context *ctx,
                                       const char *device_id,
                                       const char *field);
/* Link: https://m2x.att.com/developer/documentation/v2/device#Update-Device-Metadata-Field */
m2x_response m2x_device_metadata_field_update(m2x_context *ctx,
                                              const char *device_id,
                                              const char *field,
                                              const char *data);

#if defined(__cplusplus)
}  /* extern "C" { */
#endif

#endif  /* M2X_DEVICE_H */
