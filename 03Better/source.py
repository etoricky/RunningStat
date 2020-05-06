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
        return 0 if self.count<=1 else self.sum/(self.count-1)
        
def main():
    assert True
    object = Welford()
    object.Add(3)
    assert object.Mean == 3
    assert object.Var == 0
    object.Add(7)
    assert object.Mean == 5
    assert object.Var == 8
    object.Add(11)
    assert object.Mean == 7
    assert object.Var == 16
    print('ok')
        
if __name__=='__main__':
    main()