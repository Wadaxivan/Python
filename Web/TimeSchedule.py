from apscheduler.schedulers.blocking import BlockingScheduler

def my_print():
    print("Python123!")
sched = BlockingScheduler()
sched.add_job(my_print, 'interval', seconds = 5)
sched.start()