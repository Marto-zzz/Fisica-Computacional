#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// ----------- Mapa caótico (Logístico) -----------
double logistic_map(double x, double r) {
    return r * x * (1.0 - x);
}

// ----------- Estadística -----------

double media(const vector<double>& data) {
    double sum = 0.0;
    for (double x : data) sum += x;
    return sum / data.size();
}

double varianza(const vector<double>& data, double mean) {
    double sum = 0.0;
    for (double x : data) sum += pow(x - mean, 2);
    return sum / data.size();
}

double asimetria(const vector<double>& data, double mean, double var) {
    double sum = 0.0;
    double std_dev = sqrt(var);

    for (double x : data) {
        sum += pow((x - mean) / std_dev, 3);
    }
    return sum / data.size();
}

// ----------- Histograma -----------
void histograma(const vector<double>& data, int bins) {
    vector<int> freq(bins, 0);

    for (double x : data) {
        int index = int(x * bins);
        if (index == bins) index = bins - 1;
        freq[index]++;
    }

    cout << "\nHistograma:\n";
    for (int i = 0; i < bins; i++) {
        double lower = (double)i / bins;
        double upper = (double)(i + 1) / bins;

        cout << fixed << setprecision(2);
        cout << "[" << lower << ", " << upper << "): ";

        for (int j = 0; j < freq[i]; j += data.size()/50 + 1) {
            cout << "*";
        }
        cout << " (" << freq[i] << ")\n";
    }
}

// ----------- MAIN -----------
int main() {
    int N = 1000000;       // cantidad de números
    double r = 3.9;      // parámetro caótico
    double x = 0.5;      // semilla inicial

    vector<double> data;

    // Generar números
    for (int i = 0; i < N; i++) {
        x = logistic_map(x, r);
        data.push_back(x);
    }

    // Calcular estadísticas
    double mean = media(data);
    double var = varianza(data, mean);
    double skew = asimetria(data, mean, var);

    // Mostrar resultados
    cout << "Resultados:\n";
    cout << "Media: " << mean << endl;
    cout << "Varianza: " << var << endl;
    cout << "Asimetria: " << skew << endl;

    // Histograma
    histograma(data, 10);

    return 0;
}