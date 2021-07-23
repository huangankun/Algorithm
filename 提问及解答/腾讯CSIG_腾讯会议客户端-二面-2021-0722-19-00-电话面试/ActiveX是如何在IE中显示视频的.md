#[ActiveX](https://zh.wikipedia.org/wiki/ActiveX)

>**ActiveX**在广义上是指微软公司的整个COM架构，但是现在通常用来称呼基于标准COM接口来实现对象链接与嵌入（OLE）的ActiveX控件。[1]后者是指从VBX发展而来的，面向微软的Internet Explorer技术而设计的以OCX为扩展名的OLE控件。通过定义容器和组件之间的接口规范，如果编写了一个遵循规范的控件，那么可以很方便地在多种容器中使用而不用修改控件的代码。同样，通过实现标准接口调用，一个遵循规范的容器可以很容易地嵌入任何遵循规范的控件。由于OLE在ActiveX控件中的应用的普及，现在OLE技术中只有少数独立于ActiveX技术，例如复合文档

##简介
>一些浏览器，例如Internet Explorer、Google Chrome、网景浏览器等等现在或曾经都在不同程度上支持ActiveX控件。这允许网页通过脚本和控件交互产生更加丰富的效果，同时也带来一些安全性的问题。Internet Explorer和一些其他应用程序同时支持ActiveX Documents接口规范，允许在一个应用程序中嵌入另一个支持这个规范的应用程序。很多应用软件，例如微软的Microsoft Office系列和Adobe的Acrobat Reader都实现了这个规范。
服务器端ActiveX组件通常是指运行在服务进程中的组件。一个典型应用是在IIS中运行的ASP脚本创建的ActiveX Data Objects，也称ADO。 市场上有很多开发工具支持开发和使用ActiveX控件。
ActiveX Documents泛指一般采用ActiveX技术作为接口所使用的文件，最早始于2000年左右，当时由于互联网的兴起，当时的软件巨擘微软为打败当时崛起的浏览器Netscape所使出策略，当时市场处于弱势的IE想要将当时微软市占率最高的office文件应用于IE上，好打败Netscape，故使出让IE浏览器不需将Office的文件转换成标准的HTML网页也能读取甚至修改编辑，因此2000后的IE均提供直接开启ActiveX Documents（如.doc.ppt...等扩展名）之文件，这项策略果然在数年后，将Netscape完全逐出市场。而由于Office的文件只有微软能解读，因此后来的浏览器如Google的Chrome就不能直接打开如PPT或DOC等文件，不过随着云计算的兴起，相信这情况将会改变

##运作原理
>使用ActiveX组件
>>1. 每一个ActiveX组件都各自用一个唯一的GUID编码在登录信息的HKEY_LOCAL_MACHINE\SOFTWARE\Classes\CLSID\[2]与HKEY_CLASSES_ROOT\CLSID\之处注册其DLL文件路径。多个ActiveX组件可以放在同一个dll文件内，但是所有开放使用的ActiveX组件都必须以各自的GUID编号登记在登录信息里。
2. 当该ActiveX组件的dll档，使用LoadLibrary[3]或LoadLibraryEx[4]的API加载后，以GetProcAddress[5]获取DllGetClassObject[6]这个定义在该dll档里的函数的进入点。
3. 接着调用DllGetClassObject，以获取IClassFactory[7]的指针。
3. 再经由IClassFactory去CreateInstance[8]，进行该ActiveX组件初始化的后续操作

##Com组件
###技术细节
>不同的COM组件类型用类ID（CLSID）标示，这是一种全局唯一标识符（GUID）。每个COM组件用一个或多个接口来暴露其功能。这些接口也采用GUID唯一标识，称为接口ID（IID）。
COM接口与几种编程语言有语言绑定，如C语言、C++、Visual Basic、Delphi语言、Python[4][5]以及Windows平台上的几种脚本语言。它们都是通过接口的方法来访问组件

###接口
>所有COM组件都实现了IUnknown接口，该接口暴露了引用计数实现的对象生命期管理与类型转换，以访问不同的预定义接口。
IUnknown接口以及基于IUnknown的定制接口包括一个指向虚函数表的指针，虚函数表中包含若干函数指针，分别指向接口所声明的函数实现。对于进程内的COM组件调用，其效率等同于C++的虚函数调用。
除了基于IUnknown的定制接口，COM也支持继承自IDispatch的dispatch接口，从而支持了用于OLE自动化的晚绑定。不能访问定制接口的编程语言（例如VBS）可以通过dispatch接口访问COM组件。Windows API提供了C语言定义COM接口的方法：
```C++
#include <objbase.h>
#undef  INTERFACE
#define INTERFACE   IClassFactory

DECLARE_INTERFACE_(IClassFactory, IUnknown)
{
                // *** IUnknown methods ***
                STDMETHOD(QueryInterface) (THIS_
                                           REFIID riid,
                                           LPVOID FAR* ppvObj) PURE;
                STDMETHOD_(ULONG,AddRef) (THIS) PURE;
                STDMETHOD_(ULONG,Release) (THIS) PURE;
  
                // *** IClassFactory methods ***
                STDMETHOD(CreateInstance) (THIS_
                                          LPUNKNOWN pUnkOuter,
                                          REFIID riid,
                                          LPVOID FAR* ppvObject) PURE;
};
  
 //      等效的C++例子:
  
            struct FAR IClassFactory : public IUnknown
            {
                virtual HRESULT STDMETHODCALLTYPE QueryInterface(
                                                    IID FAR& riid,
                                                    LPVOID FAR* ppvObj) = 0;
                virtual HRESULT STDMETHODCALLTYPE AddRef(void) = 0;
                virtual HRESULT STDMETHODCALLTYPE Release(void) = 0;
                virtual HRESULT STDMETHODCALLTYPE CreateInstance(
                                                LPUNKNOWN pUnkOuter,
                                                IID FAR& riid,
                                                LPVOID FAR* ppvObject) = 0;
            };
 
 //      C语言宏扩展后是这样的:
  
            typedef struct IClassFactory
            {
                const struct IClassFactoryVtbl FAR* lpVtbl;
            } IClassFactory;
  
            typedef struct IClassFactoryVtbl IClassFactoryVtbl;
  
            struct IClassFactoryVtbl
            {
                HRESULT (STDMETHODCALLTYPE * QueryInterface) (
                                                    IClassFactory FAR* This,
                                                    IID FAR* riid,
                                                    LPVOID FAR* ppvObj) ;
                HRESULT (STDMETHODCALLTYPE * AddRef) (IClassFactory FAR* This) ;
                HRESULT (STDMETHODCALLTYPE * Release) (IClassFactory FAR* This) ;
                HRESULT (STDMETHODCALLTYPE * CreateInstance) (
                                                    IClassFactory FAR* This,
                                                    LPUNKNOWN pUnkOuter,
                                                    IID FAR* riid,
                                                    LPVOID FAR* ppvObject);
                HRESULT (STDMETHODCALLTYPE * LockServer) (
                                                    IClassFactory FAR* This,
                                                    BOOL fLock);
            };
```

###引用计数
>所有COM对象采用引用计数管理对象的生命期。客户程序通过所有COM对象都要强制实现的IUnknown接口的AddRef与Release方法来控制引用计数。当引用计数降到0时，COM对象自己负责释放内存。即对动态分配内存创建的COM对象，其Release函数内部引用计数降为0时，就释放自身所占的动态分配内存。有的COM对象（如IClassFactory）往往是静态对象，Release函数内部引用计数降为0时不需做额外的操作。
特定语言（例如Visual Basic）提供了自动引用计数，所以COM对象开发者在源代码中不需要显式维护任何内部的引用计数。C/C++编程者或者执行显式的引用计数，或者使用智能指针（如MFC提供的CComPtr）自动管理引用计数[需要解释]。
下述是如何调用COM对象的AddRef与Release的指引：
函数、方法返回接口的引用（通过返回值或者"out"参数），应当在返回前增加被返回的对象的引用计数。
接口指针被覆盖或超出作用域之前，必须调用接口指针的Release方法。
如果一个接口引用指针被复制，必须调用该指针的AddRef方法。
AddRef与Release必须在被引用的相关接口上调用。因为一个COM对象可能实现了逐个接口上的引用计数，使得仅在相关接口上内部分配资源。
不向远程对象发出引用计数的调用。代理模块保持着远程对象的一个引用，并维持着它自己的本地引用计数。
为简化COM开发，引入了活动模板库（Active Template Library，ATL）用于C++开发。ATL提供了更高层次的COM开发范式。ATL也有益于COM客户应用程序开发摆脱直接维护引用计数，而是用智能指针对象。
其他能直接支持COM的库与语言还包括MFC Visual C++编译器的COM支持[6]、VBScript、Visual Basic、ECMAScript（JavaScript）和Borland Delphi等