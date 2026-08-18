class Semaphore{
    public:
    Semaphore() {};
    Semaphore(int c) : count(c){};

    void setCount(int c){
        count = c;
    }

    inline void signal(){
        unique_lock<mutex> lock(m);
        count++;
        if(count <= 0){
            c.notify_one();
        }
    }

    inline void wait(){
        unique_lock<mutex> lock(m);
        count--;
        while(count < 0){
            c.wait(lock);
        }
    }

    private:
    mutex m;
    condition_variable c;
    int count;
};

class DiningPhilosophers {
    Semaphore fork[5];
    mutex m, l;
public:
    DiningPhilosophers() {
        for(int i = 0; i < 5; i++){
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                        {
                            lock_guard<mutex> lock(m);
                            fork[(philosopher + 1) % 5].wait();
                            fork[philosopher].wait();
                        }
                        pickLeftFork();
                        pickRightFork();
                        eat();

                        putLeftFork();
                        fork[(philosopher + 1) % 5].signal();
                        putRightFork();
                        fork[philosopher].signal();
    }
};