#include <vector>

using namespace std;

#define N 100

vector<int> operator*(vector<int> &vec, vector<int *> &matrix) {
    vector<int> res(vec.size());
    int sum;

    for (int i = 0; i < vec.size(); ++i) {
        sum = 0;
        for (int j = 0; j < vec.size(); ++j) {
            sum += vec[j] * matrix[i][j];
        }

        res[i] = sum;
    }

    return res;
}

vector<int> operator*(vector<int *> &matrix, vector<int> &vec) {
    vector<int> res(vec.size());
    int sum;

    for (int i = 0; i < vec.size(); ++i) {
        sum = 0;
        for (int j = 0; j < vec.size(); ++j) {
            sum += matrix[i][j] * vec[j];
        }

        res[i] = sum;
    }

    return res;
}

int operator*(vector<int> &vec, vector<int> &vec2) {
    int res = 0;

    for (int i = 0; i < vec.size(); ++i) {
        res += vec[i] * vec2[i];
    }

    return res;
}

int main() {

    vector<int> x(N, 1);
    vector<int *> A(N, new int[N]);
    vector<int> diag(N);

    //diag init
    for (int i = 0; i < N; i++) {
        diag[i] = 100 - i;
    }

    // ver
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            A[i][j] = 0;
        }
    }

    // diag
    for (int i = 0; i < N; ++i) {
        A[i][i] = diag[i];
    }

    // var
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            A[i][j] = 0;
        }
    }

    while (true){
        
        break;
    }

    return 0;
}