import unittest

import HTMLTestRunner

# ----------------------------------------------------------------------

def safe_unicode(obj, *args):
    try:
        return unicode(obj, *args)
    except UnicodeDecodeError:
        # obj is byte string
        ascii_text = str(obj).encode('string_escape')
        return unicode(ascii_text)

def safe_str(obj):
    """ return the byte string representation of obj """
    try:
        return str(obj)
    except UnicodeEncodeError:
        # obj is unicode
        return unicode(obj).encode('unicode_escape')

# ----------------------------------------------------------------------
# Sample tests to drive the HTMLTestRunner

class SampleTest0(unittest.TestCase):
    def __init__(self, methodName):
        unittest.TestCase.__init__(self, methodName)

    def test_pass_no_output(self):
        pass

class SampleTest1(unittest.TestCase):
    def test_fail(self):
        u""" test description (描述) """
        self.fail()

class SampleOutputTestBase(unittest.TestCase):
    def test_1(self):
        print self.MESSAGE
    def test_2(self):
        print >>sys.stderr, self.MESSAGE
    def test_3(self):
        self.fail(self.MESSAGE)
    def test_4(self):
        raise RuntimeError(self.MESSAGE)

class SampleTestBasic(SampleOutputTestBase):
    MESSAGE = 'basic test'

class SampleTestHTML(SampleOutputTestBase):
    MESSAGE = 'the message is 5 symbols: <>&"\'\nplus the HTML entity string: [&copy;] on a second line'

class SampleTestLatin1(SampleOutputTestBase):
    MESSAGE = u'the message is áéíóú'.encode('latin-1')

class SampleTestUnicode(SampleOutputTestBase):
    MESSAGE = u'the message is \u8563'
    def test_pass(self):
        u""" A test with Unicode (統一碼) docstring """
        pass


class Test_HTMLTestRunner(unittest.TestCase):

    def test0(self):
        self.suite = unittest.TestSuite()
        buf = StringIO.StringIO()
        runner = HTMLTestRunner.HTMLTestRunner(buf)
        runner.run(self.suite)
        self.assert_('</html>' in buf.getvalue())

    def test_main(self):
        self.suite = unittest.TestSuite()
        self.suite.addTests([
            unittest.defaultTestLoader.loadTestsFromTestCase(SampleTest0),
            unittest.defaultTestLoader.loadTestsFromTestCase(SampleTest1),
            unittest.defaultTestLoader.loadTestsFromTestCase(SampleTestBasic),
            unittest.defaultTestLoader.loadTestsFromTestCase(SampleTestHTML),
            unittest.defaultTestLoader.loadTestsFromTestCase(SampleTestLatin1),
            unittest.defaultTestLoader.loadTestsFromTestCase(SampleTestUnicode),
            ])

        # Invoke TestRunner
        buf = StringIO.StringIO()
        #runner = unittest.TextTestRunner(buf)       #DEBUG: this is the unittest baseline
        runner = HTMLTestRunner.HTMLTestRunner(
                    stream=buf,
                    title='<Demo Test>',
                    description='This demonstrates the report output by HTMLTestRunner.'
                    )
        runner.run(self.suite)

        # Define the expected output sequence. This is imperfect but should
        # give a good sense of the well being of the test.
        EXPECTED = u
        byte_output = buf.getvalue()
        # output the main test output for debugging & demo
        print byte_output
        # HTMLTestRunner pumps UTF-8 output
        output = byte_output.decode('utf-8')
        self._checkoutput(output,EXPECTED)


    def _checkoutput(self,output,EXPECTED):
        i = 0
        for lineno, p in enumerate(EXPECTED.splitlines()):
            if not p:
                continue
            j = output.find(p,i)
            if j < 0:
                self.fail(safe_str('Pattern not found lineno %s: "%s"' % (lineno+1,p)))
            i = j + len(p)




import unittest
if __name__ == "__main__":
    if len(sys.argv) > 1:
        argv = sys.argv
    else:
        argv=['test_HTMLTestRunner.py', 'Test_HTMLTestRunner']
    unittest.main(argv=argv)
