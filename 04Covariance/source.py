class Covariance(object):
    def __init__(self):
        self.count = 0
        self.meanx = 0
        self.sum = 0
    def AddOne(self, x):
        self.Add(x, x)
    def Add(self, x, y):
        try:
            float(x)
            self.count += 1
            last_meanx = self.meanx
            self.meanx = self.meanx + (x - self.meanx) * 1.0 / self.count
            self.sum = self.sum + (x - last_meanx) * (x - self.meanx)
        except ValueError:
            pass
    @property
    def Count(self):
        return self.count
    @property
    def MeanX(self):
        return self.meanx
    @property
    def Var(self):
        if self.count==1:
            return 0
        return self.sum/(self.count-1)
        
def main():
    assert True
    object = Covariance()
    object.AddOne(3)
    assert object.MeanX == 3
    assert object.Var == 0
    object.AddOne(7)
    assert object.MeanX == 5
    assert object.Var == 8
    object.AddOne(11)
    assert object.MeanX == 7
    assert object.Var == 16
    print('ok')
        
if __name__=='__main__':
    main()