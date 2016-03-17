using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace TestWindow {
    public partial class Form1 : Form {
        AxSafeTextBoxControlLib.AxSafeTextBoxControl SafeTextBox1 = null;
        public Form1() {
            InitializeComponent();
        }

        private void Form1_Shown(object sender, EventArgs e) {
            SafeTextBox1 = new AxSafeTextBoxControlLib.AxSafeTextBoxControl();
            panel1.Controls.Add(SafeTextBox1);


        }

        private void button1_Click(object sender, EventArgs e) {
            MessageBox.Show(SafeTextBox1.SafeText);
        }
    }
}
