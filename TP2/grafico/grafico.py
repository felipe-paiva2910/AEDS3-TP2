import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

tabela = pd.read_csv("tempos.csv",sep = ";", header = 0).to_numpy()
x = tabela[:,0]
y1 = tabela[:,1]
y2 = tabela[:,2]
y3 = tabela[:,3]

sns.set(style='ticks', font_scale=1.0, rc = {'axes.facecolor': 'white','figure.facecolor': 'white'})

ig, ax = plt.subplots(figsize=(10, 6))
sns.lineplot(data=tabela,x=x ,y=y1 , label = "Rusage User", color='blue', linewidth=2)
sns.lineplot(data=tabela,x=x ,y=y2 , label = "Rusage System", color='green', linewidth=2)
sns.lineplot(data=tabela,x= x,y= y3, label = "gettintimeofday", color='red', linewidth=2)
ax.set_xlabel('Tamanho da entrada', fontsize=10, fontweight='bold')
ax.set_ylabel('Tempo(em ms)', fontsize=10, fontweight='bold')
ax.tick_params(axis='both', which='major', labelsize=10)

plt.title('Estratégia 2')
plt.legend( title_fontsize=10, loc='upper left', fontsize=8)


plt.savefig('estrategia 2.png', dpi=300, bbox_inches='tight')


plt.show()