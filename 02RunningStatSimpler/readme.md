Background
==========

It is a simpler version from [here](https://www.johndcook.com/blog/standard_deviation/)

```
class Simpler
{
public:
    void Push(double x) {
        count++;
        const double newMean = mean + (x - mean) / count;
        const double newSum = sum + (x - mean) * (x - newMean);
        mean = newMean;
        sum = newSum;
    }
    int Count() const {
        return count;
    }
    double Mean() const {
        return (count > 0) ? mean : 0.0;
    }
    double Variance() const {
        return ((count > 1) ? sum / (count - 1) : 0.0);
    }
    double StandardDeviation() const {
        return sqrt(Variance());
    }
private:
    int count = 0;
    double mean = 0, sum = 0;
};
```

