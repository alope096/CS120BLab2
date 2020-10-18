# Array of tests to run (in order)
# Each test contains
#   description - 
#   steps - A list of steps to perform, each step can have
#       inputs - A list of tuples for the inputs to apply at that step
#       *time - The time (in ms) to wait before continuing to the next step 
#           and before checking expected values for this step. The time should be a multiple of
#           the period of the system
#       *iterations - The number of clock ticks to wait (periods)
#       expected - The expected value at the end of this step (after the "time" has elapsed.) 
#           If this value is incorrect the test will fail early before completing.
#       * only one of these should be used
#   expected - The expected output (as a list of tuples) at the end of this test
# An example set of tests is shown below. It is important to note that these tests are not "unit tests" in 
# that they are not ran in isolation but in the order shown and the state of the device is not reset or 
# altered in between executions (unless preconditions are used).
tests = [ {'description': 'Setting PINA to 64, PINB to 64 , PINC to 64',
    'steps': [ {'inputs': [('PINA',64)], 'iterations': 1 },
               {'inputs': [('PINB',64)], 'iterations': 1 },
               {'inputs': [('PINC',64)], 'iterations': 1 } ],
    'expected': [('PORTD',0x31)],
    },
    {'description': 'Setting PINA to 0, PINB to 35 , PINC to 85',
    'steps': [ {'inputs': [('PINA',0)], 'iterations': 1 },
               {'inputs': [('PINB',35)], 'iterations': 1 },
               {'inputs': [('PINC',85)], 'iterations': 1 } ],
    'expected': [('PORTD',0x1E)],
    },
    {'description': 'Setting PINA to 85, PINB to 56 , PINC to 0',
    'steps': [ {'inputs': [('PINA',0)], 'iterations': 1 },
               {'inputs': [('PINB',56)], 'iterations': 1 },
               {'inputs': [('PINC',85)], 'iterations': 1 } ],
    'expected': [('PORTD',0x22)],
    },
  
    ]

# Optionally you can add a set of "watch" variables these need to be global or static and may need
# to be scoped at the function level (for static variables) if there are naming conflicts. The 
# variables listed here will display everytime you hit (and stop at) a breakpoint
watch = ['main::seatA','main::seatB', 'main::seatC','main::totalweight','main::average','main::weight','PORTA','PORTB','PORTC','PORTD', 'PINA', 'PINB', 'PINC']

