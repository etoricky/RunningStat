class Covariance(object):
    def __init__(self):
        self.count = 0
        self.meanx = 0
        self.meany = 0
        self.sumx = 0
        self.sumy = 0
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
        if self.count==1:
            return 0
        return self.sumx/(self.count-1)
    @property
    def VarY(self):
        if self.count==1:
            return 0
        return self.sumy/(self.count-1)
        
def main():
    assert True
    object = Covariance()
    object.AddOne(3)
    assert object.MeanX == 3
    assert object.MeanY == 3
    assert object.VarX == 0
    assert object.VarY == 0
    object.AddOne(7)
    assert object.MeanX == 5
    assert object.MeanY == 5
    assert object.VarX == 8
    assert object.VarY == 8
    object.AddOne(11)
    assert object.MeanX == 7
    assert object.MeanY == 7
    assert object.VarX == 16
    assert object.VarY == 16
    print('ok')
        
if __name__=='__main__':
    main()