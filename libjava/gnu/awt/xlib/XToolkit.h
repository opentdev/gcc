
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __gnu_awt_xlib_XToolkit__
#define __gnu_awt_xlib_XToolkit__

#pragma interface

#include <gnu/java/awt/ClasspathToolkit.h>
#include <gcj/array.h>

extern "Java"
{
  namespace gnu
  {
    namespace awt
    {
      namespace xlib
      {
          class XEventLoop;
          class XGraphicsConfiguration;
          class XToolkit;
      }
    }
    namespace gcj
    {
      namespace xlib
      {
          class Display;
      }
    }
    namespace java
    {
      namespace awt
      {
          class EmbeddedWindow;
        namespace peer
        {
            class ClasspathFontPeer;
            class EmbeddedWindowPeer;
        }
      }
    }
  }
  namespace java
  {
    namespace awt
    {
        class Button;
        class Canvas;
        class Checkbox;
        class CheckboxMenuItem;
        class Choice;
        class Component;
        class Dialog;
        class Dimension;
        class EventQueue;
        class FileDialog;
        class Font;
        class FontMetrics;
        class Frame;
        class GraphicsDevice;
        class GraphicsEnvironment;
        class Image;
        class Label;
        class List;
        class Menu;
        class MenuBar;
        class MenuItem;
        class Panel;
        class PopupMenu;
        class PrintJob;
        class ScrollPane;
        class Scrollbar;
        class TextArea;
        class TextField;
        class Window;
      namespace datatransfer
      {
          class Clipboard;
      }
      namespace dnd
      {
          class DragGestureEvent;
          class DragGestureListener;
          class DragGestureRecognizer;
          class DragSource;
        namespace peer
        {
            class DragSourceContextPeer;
        }
      }
      namespace im
      {
          class InputMethodHighlight;
      }
      namespace image
      {
          class ColorModel;
          class ImageObserver;
          class ImageProducer;
      }
      namespace peer
      {
          class ButtonPeer;
          class CanvasPeer;
          class CheckboxMenuItemPeer;
          class CheckboxPeer;
          class ChoicePeer;
          class DialogPeer;
          class FileDialogPeer;
          class FontPeer;
          class FramePeer;
          class LabelPeer;
          class ListPeer;
          class MenuBarPeer;
          class MenuItemPeer;
          class MenuPeer;
          class PanelPeer;
          class PopupMenuPeer;
          class RobotPeer;
          class ScrollPanePeer;
          class ScrollbarPeer;
          class TextAreaPeer;
          class TextFieldPeer;
          class WindowPeer;
      }
    }
    namespace net
    {
        class URL;
    }
  }
}

class gnu::awt::xlib::XToolkit : public ::gnu::java::awt::ClasspathToolkit
{

public:
  XToolkit();
  virtual void flushIfIdle();
public: // actually protected
  virtual ::java::awt::peer::ButtonPeer * createButton(::java::awt::Button *);
  virtual ::java::awt::peer::TextFieldPeer * createTextField(::java::awt::TextField *);
  virtual ::java::awt::peer::LabelPeer * createLabel(::java::awt::Label *);
  virtual ::java::awt::peer::ListPeer * createList(::java::awt::List *);
  virtual ::java::awt::peer::CheckboxPeer * createCheckbox(::java::awt::Checkbox *);
  virtual ::java::awt::peer::ScrollbarPeer * createScrollbar(::java::awt::Scrollbar *);
  virtual ::java::awt::peer::ScrollPanePeer * createScrollPane(::java::awt::ScrollPane *);
  virtual ::java::awt::peer::TextAreaPeer * createTextArea(::java::awt::TextArea *);
  virtual ::java::awt::peer::ChoicePeer * createChoice(::java::awt::Choice *);
  virtual ::java::awt::peer::FramePeer * createFrame(::java::awt::Frame *);
  virtual ::java::awt::peer::CanvasPeer * createCanvas(::java::awt::Canvas *);
  virtual ::java::awt::peer::PanelPeer * createPanel(::java::awt::Panel *);
  virtual ::java::awt::peer::WindowPeer * createWindow(::java::awt::Window *);
  virtual ::java::awt::peer::DialogPeer * createDialog(::java::awt::Dialog *);
  virtual ::java::awt::peer::MenuBarPeer * createMenuBar(::java::awt::MenuBar *);
  virtual ::java::awt::peer::MenuPeer * createMenu(::java::awt::Menu *);
  virtual ::java::awt::peer::PopupMenuPeer * createPopupMenu(::java::awt::PopupMenu *);
  virtual ::java::awt::peer::MenuItemPeer * createMenuItem(::java::awt::MenuItem *);
  virtual ::java::awt::peer::FileDialogPeer * createFileDialog(::java::awt::FileDialog *);
  virtual ::java::awt::peer::CheckboxMenuItemPeer * createCheckboxMenuItem(::java::awt::CheckboxMenuItem *);
  virtual ::java::awt::peer::FontPeer * getFontPeer(::java::lang::String *, jint);
public:
  virtual ::java::awt::Dimension * getScreenSize();
  virtual jint getScreenResolution();
  virtual ::java::awt::image::ColorModel * getColorModel();
  virtual JArray< ::java::lang::String * > * getFontList();
  virtual ::java::awt::FontMetrics * getFontMetrics(::java::awt::Font *);
  virtual void sync();
  virtual ::java::awt::Image * getImage(::java::lang::String *);
  virtual ::java::awt::Image * getImage(::java::net::URL *);
  virtual ::java::awt::Image * createImage(::java::lang::String *);
  virtual ::java::awt::Image * createImage(::java::net::URL *);
  virtual jboolean prepareImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *);
  virtual jint checkImage(::java::awt::Image *, jint, jint, ::java::awt::image::ImageObserver *);
  virtual ::java::awt::Image * createImage(::java::awt::image::ImageProducer *);
  virtual ::java::awt::Image * createImage(JArray< jbyte > *, jint, jint);
  virtual void beep();
  virtual ::java::awt::datatransfer::Clipboard * getSystemClipboard();
public: // actually protected
  virtual ::java::awt::EventQueue * getSystemEventQueueImpl();
public:
  virtual ::java::awt::PrintJob * getPrintJob(::java::awt::Frame *, ::java::lang::String *, ::java::util::Properties *);
public: // actually package-private
  virtual ::gnu::awt::xlib::XGraphicsConfiguration * getDefaultXGraphicsConfiguration();
public:
  virtual ::java::awt::dnd::peer::DragSourceContextPeer * createDragSourceContextPeer(::java::awt::dnd::DragGestureEvent *);
  virtual ::java::awt::dnd::DragGestureRecognizer * createDragGestureRecognizer(::java::lang::Class *, ::java::awt::dnd::DragSource *, ::java::awt::Component *, jint, ::java::awt::dnd::DragGestureListener *);
  virtual ::java::util::Map * mapInputMethodHighlight(::java::awt::im::InputMethodHighlight *);
  virtual ::java::awt::GraphicsEnvironment * getLocalGraphicsEnvironment();
  virtual ::gnu::java::awt::peer::ClasspathFontPeer * getClasspathFontPeer(::java::lang::String *, ::java::util::Map *);
  virtual ::java::awt::Font * createFont(jint, ::java::io::InputStream *);
  virtual ::java::awt::peer::RobotPeer * createRobot(::java::awt::GraphicsDevice *);
  virtual ::gnu::java::awt::peer::EmbeddedWindowPeer * createEmbeddedWindow(::gnu::java::awt::EmbeddedWindow *);
  virtual jboolean nativeQueueEmpty();
  virtual void wakeNativeQueue();
  virtual void iterateNativeQueue(::java::awt::EventQueue *, jboolean);
public: // actually package-private
  static ::gnu::awt::xlib::XToolkit * INSTANCE;
  ::gnu::gcj::xlib::Display * __attribute__((aligned(__alignof__( ::gnu::java::awt::ClasspathToolkit)))) display;
  ::java::awt::EventQueue * queue;
  ::gnu::awt::xlib::XEventLoop * eventLoop;
  ::gnu::awt::xlib::XGraphicsConfiguration * defaultConfig;
public:
  static ::java::lang::Class class$;
};

#endif // __gnu_awt_xlib_XToolkit__
