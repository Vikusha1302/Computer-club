using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using OurClasses;

namespace KPILab7CSharp
{

    public partial class Form1 : Form
    {
        Admin admin = new Admin();
        Player[] players = new Player[20];
        int counter = 0;
        public Form1()
        {
            for (int i = 0; i < 20; i++)
            {
                players[i] = new Player();
            }
          
            InitializeComponent();
            label2.Visible = false;
            label3.Visible = false;
            label4.Visible = false;
            label5.Visible = false;
            label6.Visible = false;
            label7.Visible = false;
            label8.Visible = false;
            textBox2.Visible = false;
            textBox3.Visible = false;
            textBox4.Visible = false;
            listBox1.Visible = false;
            listBox2.Visible = false;
            button2.Visible = false;
            button3.Visible = false;
            button4.Visible = false;
            button5.Visible = false;
            richTextBox1.Visible = false;
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            int hours;
            Int32.TryParse(textBox4.Text, out hours);
            if (hours <= 3)
            {
                label8.Text = (hours * 60).ToString()+"$";
            }
            else if (hours > 3 && hours <= 6)
            {
                label8.Text = (hours * 55).ToString() + "$";
            }
            else if (hours > 6)
            {
                label8.Text = (hours * 50).ToString() + "$";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            players[counter].name = textBox2.Text;
            players[counter].phonenumber = textBox3.Text;
            Int32.TryParse(textBox4.Text, out players[counter].playtime);
            players[counter].money = label8.Text;
            players[counter].computermodel = listBox1.Text;
            players[counter].game = listBox2.Text;
            MessageBox.Show("Игрок успешно добавлен в базу!");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            counter++;
            textBox2.Text = "";
            textBox3.Text = "";
            textBox4.Text = "";
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (!richTextBox1.Visible)
            {
                richTextBox1.AppendText("Администратора зовут: " + admin.name + Environment.NewLine + "--------" + Environment.NewLine+ "Список игроков:"+ Environment.NewLine+"--------"+Environment.NewLine);

                for (int i=0; i<=counter; i++)
                {
                    richTextBox1.AppendText("Имя игрока: " + players[i].name + Environment.NewLine + "Номер телефона: " + players[i].phonenumber + Environment.NewLine + "Заплачено денег: " + players[i].money + Environment.NewLine + "Время игры: " + players[i].playtime.ToString() + Environment.NewLine + "Модель компьютера: " + players[i].computermodel + Environment.NewLine + "Игра: " + players[i].game + Environment.NewLine + "--------" + Environment.NewLine);
                }
                richTextBox1.Visible = true;
                richTextBox1.BringToFront();
            }
            else
            {
                richTextBox1.Text = "";
                richTextBox1.Visible = false;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            admin.name = textBox1.Text;
            label1.Text = "Добро пожаловать, " + admin.name+"!";
            textBox1.Visible = false;
            button1.Visible = false;

            label2.Visible = true;
            label3.Visible = true;
            label4.Visible = true;
            label5.Visible = true;
            label6.Visible = true;
            label7.Visible = true;
            label8.Visible = true;
            textBox2.Visible = true;
            textBox3.Visible = true;
            textBox4.Visible = true;
            listBox1.Visible = true;
            listBox2.Visible = true;
            button2.Visible = true;
            button3.Visible = true;
            button4.Visible = true;
            button5.Visible = true;
        }
    }
}

namespace OurClasses
{
    class Admin
    {
        public string name;
    };

    class Player : Admin
    {
        public string name,computermodel,game,money,phonenumber;
        public int playtime;
    };
}
