Background
==========

I think this rewritten version is better compared to the code [here](https://www.johndcook.com/blog/standard_deviation/)

```
class Welford {
public:
    void Add(double x) {
        count++;
        const double last_mean = mean;
        mean = mean + (x - mean) / count;
        sum = sum + (x - last_mean) * (x - mean);
    }
    int Count() const {
        return count;
    }
    double Mean() const {
        return (count > 0) ? mean : 0.0;
    }
    double Var() const {
        return ((count > 1) ? sum / (count - 1) : 0.0);
    }
    double Std() const {
        return sqrt(Var());
    }
private:
    int count = 0;
    double mean = 0, sum = 0;
};
```

