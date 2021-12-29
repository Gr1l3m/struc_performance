#include <iostream>
using namespace std;

// Variable declaration:


// function declaration
float spectrum_point(float, float, float, float, float, float, float, float, float, float);

int main()
{
	cout << spectrum_point(1.f, 0.66, 1.f, 1.43, 1.f, 1.f, 0.89, 1.f, 1.f, 3.48) << endl;

}


// function definition
float spectrum_point(float t, float kd, float beta_d, float scr, float fa, float na, float s1r, float fv, float nv, float tl) {

    float scs = scr * fa * na;
    float s1s = s1r * fv * nv;

    float scd = scs * kd;
    float s1d = s1s * kd;

    float ts = s1s / scs;
    float t0 = ts * 0.2;

    float sa;

    if (t < t0) {
        sa = scd * (0.4 + (0.6 * (t / t0)));
    }
    else if (t < ts) {
        sa = scd;
    }
    else if (t < tl) {
        sa = min(s1d / t, scd);
    }
    else {
        sa = (s1d / pow(t, 2)) * tl;
    }

	return sa;
}
