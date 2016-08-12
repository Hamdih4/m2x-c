#include <stdio.h>

#include "m2x.h"
#include "device.h"

const char *M2X_KEY = "2531f2f7c94b916acc0928653924ff5a";
const char *device_id = "238b227c4ccb62b7af44e81fcc6d47fb";

int main()
{
  m2x_context *ctx = NULL;
  m2x_response response;

  const char *from = "2015-01-01T01:00:00.000Z";
  const char *end = "2016-01-01T01:00:00.000Z";

  char buf[2048];

  ctx = m2x_open(M2X_KEY);

  sprintf(buf, "{\"from\": \"%s\", \"end\": \"%s\"}", from, end);

  printf("Deleting location hisory from: %s end: %s for device: %s\n", from, end, device_id);

  response = m2x_device_delete_location_history(ctx, device_id, buf);
  
  printf("Status code: %d\n", response.status);
  
  if (m2x_is_success(&response) && response.raw) {
    printf("%s\n", response.raw);
  }

  m2x_release_response(&response);
  m2x_close(ctx);
  
  return 0;
}
