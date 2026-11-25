#include <iostream>

using namespace std;

class Double
{
private:
    double value;

public:
    void setZero()
    {
        value = 0.0;
    }

    void setInt(int v)
    {
        value = v;
    }

    void show() const
    {
        cout << value << endl;
    }

    Double add(Double& other) const
    {
        Double result;
        result.value = value + other.value;
        return result;
    }
};

int main()
{
    Double d1, d2, d3;

    d1.setInt(10);
    d2.setInt(25);

    d3 = d1.add(d2);

    cout << "d1 = "; d1.show();
    cout << "d2 = "; d2.show();
    cout << "d3 = d1 + d2 = "; d3.show();

    return 0;
}