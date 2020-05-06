Background
==========

This implementation is the one on Wikipedia [here](https://en.wikipedia.org/wiki/Algorithms_for_calculating_variance#Online)  

The corresponding mathematical formula is  
![Image description](https://wikimedia.org/api/rest_v1/media/math/render/svg/f440f49beea73d0aeec36d0101caa20f89e864aa)

cpp
===
```
class Covariance {
public:
	void Add(double x) {
		Add(x, x);
	}
	void Add(double x, double y) {
		count++;
		const double last_meanx = meanx, last_meany = meany;
		meanx = meanx + (x - meanx) / count;
		meany = meany + (y - meany) / count;
		sumx = sumx + (x - last_meanx) * (x - meanx);
		sumy = sumy + (y - last_meany) * (y - meany);
		sum = sum + (x - last_meanx) * (y - meany);
	}
	int Count() const {
		return count;
	}
	double MeanX() const {
		return meanx;
	}
	double MeanY() const {
		return meany;
	}
	double VarX() const {
		return ((count > 1) ? sumx / (count - 1) : 0.0);
	}
	double VarY() const {
		return ((count > 1) ? sumy / (count - 1) : 0.0);
	}
	double Cov() const {
		return ((count > 1) ? sum / (count - 1) : 0.0);
	}
	double Std() const {
		return sqrt(Cov());
	}
private:
	int count = 0;
	double meanx = 0, meany = 0, sum = 0, sumx = 0, sumy = 0;
};
```

py
==
```
class Covariance(object):
    def __init__(self):
        self.count = 0
        self.meanx = 0
        self.meany = 0
        self.sumx = 0
        self.sumy = 0
        self.sum = 0
    def AddOne(self, x):
        self.Add(x, x)
    def Add(self, x, y):
        try:
            float(x)
            self.count += 1
            last_meanx = self.meanx
            last_meany = self.meany
            self.meanx = self.meanx + (x - self.meanx) * 1.0 / self.count
            self.meany = self.meany + (y - self.meany) * 1.0 / self.count
            self.sumx = self.sumx + (x - last_meanx) * (x - self.meanx)
            self.sumy = self.sumy + (y - last_meany) * (y - self.meany)
            self.sum = self.sum + (x - last_meanx) * (y - self.meany)
        except ValueError:
            pass
    @property
    def Count(self):
        return self.count
    @property
    def MeanX(self):
        return self.meanx
    @property
    def MeanY(self):
        return self.meany
    @property
    def VarX(self):
        return 0 if self.count<=1 else self.sumx/(self.count-1)
    @property
    def VarY(self):
        return 0 if self.count<=1 else self.sumy/(self.count-1)
    @property
    def Cov(self):
        return 0 if self.count<=1 else self.sum/(self.count-1)
```