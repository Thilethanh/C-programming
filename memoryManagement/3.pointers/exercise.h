// main3.c - Pointer Basics
//
typedef struct CodeFile {
  int lines;
  int filetype;
} codefile_t;

codefile_t change_filetype(codefile_t *f, int new_filetype);

// main4.c - C Arrays
void update_file(int filedata[200], int new_filetype, int new_num_lines);


// main5.c - Array Casting
typedef struct Graphics {
  int fps;
  int height;
  int width;
} graphics_t;

void dump_graphics(graphics_t gsettings[10]);

// main6.c - C Strings
void concat_strings(char *str1, const char *str2);


// main7.c - C string lib
#include <string.h>

typedef struct {
  size_t length;
  char buffer[64];
} TextBuffer;

int smart_append(TextBuffer* dest, const char* src);


// main8.c - Forward Declaration
/*Sometimes you have a struct that may need to reference itself, or be used recursively.
 *A forward declaration lets the compiler know about the existence of a struct type before it's fully defined:
 */

typedef struct SnekObject snekobject_t;

typedef struct SnekObject {
  char *name;
  snekobject_t *child;
} snekobject_t;

snekobject_t new_node(char *name);


// main9.c - Mutual Struct
typedef struct Employee employee_t;
typedef struct Department department_t;

struct Employee {
  int id;
  char *name;
  struct Department *department;
};

struct Department {
  char* name;
  struct Employee *manager;
  
};

employee_t create_employee(int id, char *name);
department_t create_department(char *name);

void assign_employee(employee_t *emp, department_t *department);
void assign_manager(department_t *dept, employee_t *manager);



