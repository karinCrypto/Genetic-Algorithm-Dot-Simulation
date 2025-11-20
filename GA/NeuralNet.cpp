// 신경망 GA 확장

#include "NeuralNet.h"

NeuralNet::NeuralNet(int in, int hid, int out)
{
    W1 = Matrix(hid, in, true);
    W2 = Matrix(out, hid, true);
}

Matrix NeuralNet::forward(const Matrix& input) {
    Matrix a = W1 * input;
    a.activate();
    Matrix out = W2 * a;
    out.activate();
    return out;
}

NeuralNet NeuralNet::crossover(const NeuralNet& other) {
    NeuralNet child(W1.cols, W1.rows, W2.rows);
    child.W1 = W1.crossover(other.W1);
    child.W2 = W2.crossover(other.W2);
    return child;
}

void NeuralNet::mutate(double rate) {
    W1.mutate(rate);
    W2.mutate(rate);
}
