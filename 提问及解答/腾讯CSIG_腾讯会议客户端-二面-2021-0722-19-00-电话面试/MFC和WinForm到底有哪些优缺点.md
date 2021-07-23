##[Winform、WPF、Silverlight、MFC区别与联系](https://www.cnblogs.com/peterYong/p/6556598.html#_label0)

###WinForm
>在Windows中，诸如窗体绘制等功能由GDI（图形设备接口）实现，放在操作系统内核中。Windows Forms在底层使用的是GDI+。GDI+是GDI的“面向对象包装”，使用C++实现。.NET Windows Forms应用程序中使用的GDI+其实是在C++实现的非托管代码之上又包了一层，从而让我们能使用C#这样的托管编程语言调用GDI+功能绘图。

>注：GDI：图形设备接口(Graphics Device Interface)，主要任务是负责系统与绘图程序之间的信息交换，处理所有Windows程序的图形和图像输出。GDI的出现使程序员无需要关心硬件设备及设备正常驱动，就可以将应用程序的输出转化为硬件设备上的输出和构成，实现了程序开发者与硬件设备的隔离，大大方便了开发工作。

###WPF
>WPF底层使用的是DirectX，(Direct eXtension，简称DX）是由微软公司创建的多媒体编程接口。由C++编程语言实现，遵循COM。就是通常用来开发游戏的那个DirectX。WPF与Windows Forms这两者并没有什么关系。按照微软的意图，WPF是用来取代WindowsForm的，所以最新的Visual Studio就使用了WPF开发界面，这是一个很明确的信号。

>当然，出于兼容目的，Windows Forms与WPF将长期并存，可以把它们看成是两套独立的界面技术。

>此外，从技术的角度，WPF比WinForm先进是不容置疑的。
1、解决Window Handle（句柄）问题 
在Windows GDI或WinForm开发中复杂的GUI应用程序，会使用的大量的控件，如Grid等。而每个控件或Grid cell都是一个小窗口，会使用一个Window handle，尽管控件厂商提供了很多优化办法，但还是会碰到Out of Memory或"Error Create Window handle"，而导致程序退出。 
WPF彻底改变了控件显示的模式，控件不在使用窗口，也就不会占用Window handle。理论上，如果一个WPF只有一个主窗口的话，WPF只会使用一个Window handle（如果忽略用于Dispatcher的隐藏窗口的话）。所以WPF GUI程序不会出现Window handle不够用的情况。 
2、多线程的处理  
在WinForm程序开发时，最头疼的一个问题就是，worker线程修改控件的属性而导致程序崩溃，而且这种非法操作并不是每次都失败。WinForm控件提供了InvokeRequired属性来判断当前线程是不是控件创建线程。问题是当控件树很深时，这个属性会比较慢。 
WPF开始设计的时候，就考虑到了多线程的问题。大部分的WPF类都继承于DispatcherObject，它实际就是对Dispatcher的一个简单封装。Dispatcher提供了类似InvokeRequired的方法(CheckAccess)。这个方法只是比较线程的ID，所以会很快。另外，Dispatcher提供了优先队列，异步调用，Timer等功能，简化了开发多线程GUI程序。 
3、控件的Composition 
在WinForm如果要实现一个有Checkbox的下拉菜单，将不得不处理复杂的Window消息。
而通过WPF控件的Content Model和Layout系统，WPF控件可以包括任何类型的控件，甚至.Net CLR对象。很多现代的控件厂商也提供了Composition的控件，实现方法和WPF的Content模型也比较相似。WPF开发团队应该借鉴了Infragistics的很多想法。有了这个基础，开发新的WPF控件更加简单了。 
4、XAML 
个人觉得XAML应该是WPF中比较划时代的东西。通过XAML，我们可以用文本的方式描述复杂的Object Graph。这个想法在VB中就有了，不过XAML更简化，以便于使用工具来生成XAML。通过Command，Routing Event等机制，界面设计人员和程序员有比较清楚的界限。 
5、Dependency Property 
在WinForm开发中，经常碰到的问题就是一个控件的值变了，其他控件也会跟着改变。解决办法，要不是通过写代码，要不是通过数据绑定，前者是界面和代码没法分开，后者还不够灵活.
而WPF在这方面通过XAML可以简单的把相关的属性联系起来，通过Extension可以实现复杂的绑定关系。 
总的来说，WPF应该是GUI发展的一个延续，原来GUI中复杂的东西，现在通过简单的文本就可以实现。

###MonoDevelop
>MonoDevelop是个适用于Linux、Mac OS X[3]和Microsoft Windows[4]的开放源代码集成开发环境，主要用来开发Mono与.NET Framework软件。MonoDevelop集成了很多Eclipse与Microsoft Visual Studio的特性，像是Intellisense、版本控制还有GUI与Web设计工具。另外还集成了GTK#GUI设计工具（叫做Stetic）。[5]目前支持的语言有Python、Vala、C♯、Java、BOO、Nemerle、Visual Basic .NET、CIL、C与C++[6][7]
>MonoDevelop也可以在Windows跟Mac OS X平台上运行。但并不是一开始就可以的，而是到2.2之后才正式可以。[8]MonoDevelop的Mac OS X版本里包含了Mono的安装程序，[9]但却因为原生OS X平台GTK的拖拉问题而没有包含Stetic可视化设计工具。[10]Mono也提供了给运行在SPARC上的Solaris 8包包，[11]给OpenSolaris用的包包则只由OpenSolaris社区里的组群提供。[12]在FreeBSD上，同样地是由FreeBSD社区提供支持

###Silverlight
>Silverlight在API层可以看成是WPF的子集，但事实上除了这点之外，Silverlight与WPF并没有任何联系。因为Silverlight应用程序不依赖于.NET Framework，只要用户计算机（或手机）安装有Silverlight运行环境（比如用户通过互联网给浏览器添加了Silverlight插件），就可以跑Silverlight应用程序，并不要求用户安装庞大的.NET Framework。Silverlight运行时环境在API层面也可以看成是标准.NET Framework的功能子集，但它完全是重新写过的，独立于标准的.NET Framework，虽然为了方便应用程序开发，微软努力保持两者在API层面的一致性，但并不排除Silverlight运行时环境日后会拥有全新的为.NET标准环境所不具备的功能。
Windows Forms/WPF/Silverlight这三者其实是独立发展的三个技术领域，只不过微软出于方便开发的目的，有意让Silverlight与WPF在应用层面开发体验（甚至包括大部分应用层代码）高度一致罢了。
从开发角度来看，Windows Forms已有多年的历史，高度成熟，拥有大量的第三方控件等各种资源，如果开发“标准”与“通用”界面类型的Windows应用程序，使用它可以获得较高的开发效率和不错的运行性能。
WPF的长处在于它可以开发非常“个性化”的Windows应用程序，你可以不受任何限制地实现你所能“梦想”到的各种用户界面，而且在动画等多媒体方面，WPF优于Windows Forms，另外，WPF的数据绑定机制也比WindowsForms要强大和灵活。WPF的短处在于它对计算机硬件的要求较高，对于硬件配置较低的计算机，其运行性能不如Windows Forms版本。就目前来看，WPF的最佳平台是Windows 7。
Windows Forms和WPF主要用于开发桌面应用程序，Silverlight主要战场是互联网，通常用它来开发RIA（丰富互联网程序）的互联网应用程序，或者是跑在手机等智能移动设备上的应用程序。可以这样说，会WPF，不费太多力气，就可以转去开发Silverlight应用程序，两者实在是太相似了，特别是界面层代码，由于都使用XAML，这使我们可以比较容易地为某一应用程序同时开发“桌面版”、“手机版”和“浏览器版”三种版本，而这三种版本其用户界面都可以拥有一致的外观和用户使用体验。
###MFC
>微软基础类库（英语：Microsoft Foundation Classes，简称MFC）是一个微软公司提供的类库（class libraries），以C++类的形式封装了Windows API，并且包含一个应用程序框架，以减少应用程序开发人员的工作量。其中包含的类包含大量Windows句柄封装类和很多Windows的内建控件和组件的封装类。

###对比MFC ，Winform ，WPF
>1. MFC 生成本机代码，自然是很快。可是，消息循环，减缓了界面显示速度
>2.  winform 封装了 win32 的api，多次进行P/invoke 操作 （大部分使用p/invoke操作封装），速度慢。
>3. wpf是一种新的模型，不再使用win32 模型，自己新建模型，使用dx 作为新的显示技术，直接访问驱动程序，加快了运行速度，可是，这种模型，需要支持dx 9 的显卡，硬件要求高（你还能找到现代机器不支持dx9 的吗？）  
>**开发效率上，MFC <WPF <winform**
>尽管MFC开发界面执行效率高但是开发效率低，作为现在的项目开发来说，时间跟开发效率往往能决定项目的成败，所以除非有特别的需求，否则都回尽量避免用mfc来做开发，MFC只是一个弱封装器。
**开发成本，MFC〉wpf〉winform**
>用MFC开发成本太高，对开发者能力要求更高，作为客服当然希望开发的费用越少越好，开发者当然希望钱赚得越多越好，这样一比，这也是MFC没落的一个很大的原因。
**界面执行效率上，MFC==WPF〉winform**
随着计算机硬件的性能提高，多核cpu的普及，它们的差距会越来越小。
**开发灵活性上：wpf〉MFC〉winform**
**美观上：Wpf〉winform〉MFC**
这一项中MFC下要开发出一个华丽的ui极其困难，也许你可以说你可以用控件，但是商业开发控件是要收费的！！Wpf很容易就可以做出vista那样的ui特效。mfc要写出这种效果不知要写到何年何月。
这样一来MFC存在的价值就更低了。效率和美观不如Wpf，开发效率又不如winform，预计不出10年，随着vista取代xp，mfc将会退出历史舞台。
**内存使用上：wpf〉winform〉MFC**
随着计算机硬件的性能提高wpf这个缺点会被忽略。
**使用范围：wpf〉MFC==winform**
有以上可知：WPF 大有取代winform 和MFC之势，从未来net的发展来看，MFC以后只会变成一种经典，作为一种技术来供开发者学习，winform和WPF两者会并存发展，但最终都会被WPF取代，最终实现桌面应用程序和浏览器应用程序的统一。