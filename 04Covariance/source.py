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
        
def main():
    assert True
    if True:
        object = Covariance()
        object.AddOne(3)
        assert object.MeanX == 3
        assert object.MeanY == 3
        assert object.VarX == 0
        assert object.VarY == 0
        assert object.Cov == 0
        object.AddOne(7)
        assert object.MeanX == 5
        assert object.MeanY == 5
        assert object.VarX == 8
        assert object.VarY == 8
        assert object.Cov == 8
        object.AddOne(11)
        assert object.MeanX == 7
        assert object.MeanY == 7
        assert object.VarX == 16
        assert object.VarY == 16
        assert object.Cov == 16
    if True:
        object = Covariance()
        object.Add(3, 11)
        assert object.MeanX == 3
        assert object.MeanY == 11
        assert object.VarX == 0
        assert object.VarY == 0
        assert object.Cov == 0
        object.Add(7, 7)
        assert object.MeanX == 5
        assert object.MeanY == 9
        assert object.VarX == 8
        assert object.VarY == 8
        assert object.Cov == -8
        object.Add(11, 3)
        assert object.MeanX == 7
        assert object.MeanY == 7
        assert object.VarX == 16
        assert object.VarY == 16
        assert object.Cov == -16
    print('ok')
        
if __name__=='__main__':
    main()