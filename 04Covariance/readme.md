Background
==========

This implementation is the one on Wikipedia [here](https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance#Online)  

The corresponding mathematical formula is  
![Image description](https://wikimedia.org/api/rest_v1/media/math/render/svg/f440f49beea73d0aeec36d0101caa20f89e864aa)

```
class Covariance {
public:
    void Add(double x, double y) {
        count++;
        const double new_meanx = meanx + (x - meanx) / count;
        const double new_meany = meany + (y - meany) / count;
        const double new_sum = sum + (x - meanx) * (y - new_meany);
        meanx = new_meanx;
        meany = new_meany;
        sum = new_sum;
    }
    int Count() const {
        return count;
    }
    double MeanX() const {
        return (count > 0) ? meanx : 0.0;
    }
    double MeanY() const {
        return (count > 0) ? meany : 0.0;
    }
    double Var() const {
        return ((count > 1) ? sum / (count - 1) : 0.0);
    }
    double Std() const {
        return sqrt(Var());
    }
private:
    int count = 0;
    double meanx = 0, meany = 0, sum = 0;
};
```
