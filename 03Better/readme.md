Background
==========

I think this rewritten version is better compared to the code [here](https://www.johndcook.com/blog/standard_deviation/)

cpp
===

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

py
==
```
class Welford(object):
    def __init__(self):
        self.count = 0
        self.mean = 0
        self.sum = 0
    def Add(self, x):
        try:
            float(x)
            self.count += 1
            last_mean = self.mean
            self.mean = self.mean + (x - self.mean) * 1.0 / self.count
            self.sum = self.sum + (x - last_mean) * (x - self.mean)
        except ValueError:
            pass
    @property
    def Count(self):
        return self.count
    @property
    def Mean(self):
        return self.mean
    @property
    def Var(self):
        if self.count==1:
            return 0
        return self.sum/(self.count-1)
```