/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param students int整型一维数组
 * @param studentsLen int students数组长度
 * @param sandwiches int整型一维数组
 * @param sandwichesLen int sandwiches数组长度
 * @return int整型
 */
int countStudents(int* students, int studentsLen, int* sandwiches,
                  int sandwichesLen) {
    int front = 0;
    int size = studentsLen;
    int sandwichIdx = 0;
    int attempts = 0;

    while (size > 0) {

        int currentStudent = students[front];

        if (currentStudent == sandwiches[sandwichIdx]) {

            front = (front + 1) % studentsLen;
            size--;
            sandwichIdx++;
            attempts = 0;
        } else {

            for (int i = front; i < front + size - 1; i++) {
                students[i % studentsLen] = students[(i + 1) % studentsLen];
            }
            students[(front + size - 1) % studentsLen] = currentStudent;
            attempts++;

            if (attempts >= size) {
                return size;
            }
        }
    }

    return 0;
}
