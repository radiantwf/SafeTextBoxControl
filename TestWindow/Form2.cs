using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TestWindow {
    public partial class Form2: Form {
        AxSafeTextBoxControlLib.AxSafeTextBoxControl SafeTextBox1 = null;
        AxSafeTextBoxControlLib.AxSafeTextBoxControl SafeTextBox2 = null;
        public Form2() {
            InitializeComponent();
        }

        private void Form2_Shown(object sender, EventArgs e) {
            SafeTextBox1 = new AxSafeTextBoxControlLib.AxSafeTextBoxControl();
            panel1.Controls.Add(SafeTextBox1);
            SafeTextBox2 = new AxSafeTextBoxControlLib.AxSafeTextBoxControl();
            panel2.Controls.Add(SafeTextBox2);


        }

        private void button1_Click(object sender, EventArgs e) {
            MessageBox.Show(SafeTextBox1.SafeText);
        }
    }
}
