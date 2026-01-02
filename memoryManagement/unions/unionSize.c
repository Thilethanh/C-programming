// A downside of unions is that the size of the union is the size of the largest field in the union.


typedef union IntOrErrMessage {
  int data;
  char err[256];
} int_or_err_message_t;

/* Imagine an array of 1000 int_or_err_message_t objects. 
 * Even if none of them make use of the .err field, 
 * the array will take up 256 * 1000 = 256,000 bytes of memory! 
 * An array of ints would have only taken 4,000 bytes (assuming 32-bit integers).
 */

union SensorData {
  long int temperature;
  long int humidity;
  long int pressure;
};

// sizeof(union SensorData) = 8 bytes
//
union PacketPayload {
  char text[256];
  unsigned char binary[256];
  struct ImageData {
    int width;
    int height;
    unsigned char data[1024];
  } image;
};

/*
 * Total:
4 + 4 + 1024 = 1032 bytes
Largest member = 1032 bytes

=> sizeof(union PacketPayload) = 1032 bytes
*/

union Item {
  struct {
    int damage;
    int range;
    int size;
  } weapon;
  struct {
    int healingAmount;
    int duration;
  } potion;
  struct {
    int doorID;
  } key;
};
/*
* weapon
3 × int = 3 × 4 = 12 bytes

* potion
2 × int = 8 bytes

* key
1 × int = 4 bytes
Largest member = 12 bytes

=> sizeof(union Item) = 12 bytes
*/
