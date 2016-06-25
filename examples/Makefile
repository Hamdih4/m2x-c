CC=gcc
CFLAGS=-O2 -Wall -Wextra -std=c89 -I..
LDFLAGS=-lcurl
M2X_LIB=../m2x.a

BINS=m2x_status list_devices create_device update_device delete_device_values serialize_json export_values  add_device_to_collection remove_device_from_collection update_temp

all: $(BINS)

m2x_status: m2x_status.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

list_devices: list_devices.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

create_device: create_device.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

update_device: update_device.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

delete_device_values: delete_device_values.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

serialize_json: serialize_json.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

export_values: export_values.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^
	
update_temp: update_temp.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

add_device_to_collection: add_device_to_collection.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

remove_device_from_collection: remove_device_from_collection.o $(M2X_LIB)
	$(CC) -o $@ $(LDFLAGS) $^

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

clean:
	rm -rf *.o $(BINS)

.PHONY: all clean
