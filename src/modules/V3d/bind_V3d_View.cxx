/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <V3d_Viewer.hxx>
#include <V3d_TypeOfView.hxx>
#include <V3d_View.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_TypeOfColor.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Aspect_FillMethod.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <V3d_TypeOfVisualization.hxx>
#include <V3d_Light.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <V3d_TypeOfAxe.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <Bnd_Box.hxx>
#include <Aspect_GradientBackground.hxx>
#include <V3d_ListOfLight.hxx>
#include <Graphic3d_CView.hxx>
#include <gp_Ax3.hxx>
#include <Aspect_Grid.hxx>
#include <Graphic3d_BufferType.hxx>
#include <Graphic3d_ExportFormat.hxx>
#include <Graphic3d_SortType.hxx>
#include <Image_PixMap.hxx>
#include <V3d_ImageDumpOptions.hxx>
#include <V3d_StereoDumpOptions.hxx>
#include <V3d_TypeOfBackfacingModel.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <Graphic3d_Camera.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <Graphic3d_DiagnosticInfo.hxx>
#include <Standard_Type.hxx>
#include <gp_Dir.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <Graphic3d_Vertex.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <gp_Pnt.hxx>
#include <V3d_ViewerPointer.hxx>
#include <NCollection_List.hxx>
#include <V3d_Trihedron.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_Group.hxx>

void bind_V3d_View(py::module &mod){

py::class_<V3d_View, opencascade::handle<V3d_View>, Standard_Transient> cls_V3d_View(mod, "V3d_View", "Defines the application object VIEW for the VIEWER application. The methods of this class allow the editing and inquiring the parameters linked to the view. Provides a set of services common to all types of view. Warning: The default parameters are defined by the class Viewer (Example : SetDefaultViewSize()). Certain methods are mouse oriented, and it is necessary to know the difference between the start and the continuation of this gesture in putting the method into operation. Example : Shifting the eye-view along the screen axes.");

// Constructors
cls_V3d_View.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("theViewer"));
cls_V3d_View.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfView>(), py::arg("theViewer"), py::arg("theType"));
cls_V3d_View.def(py::init<const opencascade::handle<V3d_Viewer> &, const opencascade::handle<V3d_View> &>(), py::arg("theViewer"), py::arg("theView"));

// Fields

// Methods
cls_V3d_View.def("SetWindow", [](V3d_View &self, const opencascade::handle<Aspect_Window> & a0) -> void { return self.SetWindow(a0); });
cls_V3d_View.def("SetWindow", (void (V3d_View::*)(const opencascade::handle<Aspect_Window> &, const Aspect_RenderingContext)) &V3d_View::SetWindow, "Activates the view in the specified Window If <aContext> is not NULL the graphic context is used to draw something in this view. Otherwise an internal graphic context is created. Warning: The view is centered and resized to preserve the height/width ratio of the window.", py::arg("theWindow"), py::arg("theContext"));
cls_V3d_View.def("SetMagnify", (void (V3d_View::*)(const opencascade::handle<Aspect_Window> &, const opencascade::handle<V3d_View> &, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &V3d_View::SetMagnify, "None", py::arg("theWindow"), py::arg("thePreviousView"), py::arg("theX1"), py::arg("theY1"), py::arg("theX2"), py::arg("theY2"));
cls_V3d_View.def("Remove", (void (V3d_View::*)() const) &V3d_View::Remove, "Destroys the view.");
cls_V3d_View.def("Update", (void (V3d_View::*)() const) &V3d_View::Update, "Deprecated, Redraw() should be used instead.");
cls_V3d_View.def("Redraw", (void (V3d_View::*)() const) &V3d_View::Redraw, "Redisplays the view even if there has not been any modification. Must be called if the view is shown. (Ex: DeIconification ) .");
cls_V3d_View.def("RedrawImmediate", (void (V3d_View::*)() const) &V3d_View::RedrawImmediate, "Updates layer of immediate presentations.");
cls_V3d_View.def("Invalidate", (void (V3d_View::*)() const) &V3d_View::Invalidate, "Invalidates view content but does not redraw it.");
cls_V3d_View.def("IsInvalidated", (Standard_Boolean (V3d_View::*)() const) &V3d_View::IsInvalidated, "Returns true if cached view content has been invalidated.");
cls_V3d_View.def("MustBeResized", (void (V3d_View::*)()) &V3d_View::MustBeResized, "Must be called when the window supporting the view changes size. if the view is not mapped on a window. Warning: The view is centered and resized to preserve the height/width ratio of the window.");
cls_V3d_View.def("DoMapping", (void (V3d_View::*)()) &V3d_View::DoMapping, "Must be called when the window supporting the view is mapped or unmapped.");
cls_V3d_View.def("IsEmpty", (Standard_Boolean (V3d_View::*)() const) &V3d_View::IsEmpty, "Returns the status of the view regarding the displayed structures inside Returns True is The View is empty");
cls_V3d_View.def("UpdateLights", (void (V3d_View::*)() const) &V3d_View::UpdateLights, "Updates the lights of the view.");
cls_V3d_View.def("SetAutoZFitMode", [](V3d_View &self, const Standard_Boolean a0) -> void { return self.SetAutoZFitMode(a0); });
cls_V3d_View.def("SetAutoZFitMode", (void (V3d_View::*)(const Standard_Boolean, const Standard_Real)) &V3d_View::SetAutoZFitMode, "Sets the automatic z-fit mode and its parameters. The auto z-fit has extra parameters which can controlled from application level to ensure that the size of viewing volume will be sufficiently large to cover the depth of unmanaged objects, for example, transformation persistent ones.", py::arg("theIsOn"), py::arg("theScaleFactor"));
cls_V3d_View.def("AutoZFitMode", (Standard_Boolean (V3d_View::*)() const) &V3d_View::AutoZFitMode, "returns TRUE if automatic z-fit mode is turned on.");
cls_V3d_View.def("AutoZFitScaleFactor", (Standard_Real (V3d_View::*)() const) &V3d_View::AutoZFitScaleFactor, "returns scale factor parameter of automatic z-fit mode.");
cls_V3d_View.def("AutoZFit", (void (V3d_View::*)() const) &V3d_View::AutoZFit, "If automatic z-range fitting is turned on, adjusts Z-min and Z-max projection volume planes with call to ZFitAll.");
cls_V3d_View.def("ZFitAll", [](V3d_View &self) -> void { return self.ZFitAll(); });
cls_V3d_View.def("ZFitAll", (void (V3d_View::*)(const Standard_Real) const) &V3d_View::ZFitAll, "Change Z-min and Z-max planes of projection volume to match the displayed objects.", py::arg("theScaleFactor"));
cls_V3d_View.def("SetBackgroundColor", (void (V3d_View::*)(const Quantity_TypeOfColor, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::SetBackgroundColor, "Defines the background color of the view by the color definition type and the three corresponding values.", py::arg("theType"), py::arg("theV1"), py::arg("theV2"), py::arg("theV3"));
cls_V3d_View.def("SetBackgroundColor", (void (V3d_View::*)(const Quantity_Color &)) &V3d_View::SetBackgroundColor, "Defines the background color of the view.", py::arg("theColor"));
cls_V3d_View.def("SetBgGradientColors", [](V3d_View &self, const Quantity_Color & a0, const Quantity_Color & a1) -> void { return self.SetBgGradientColors(a0, a1); });
cls_V3d_View.def("SetBgGradientColors", [](V3d_View &self, const Quantity_Color & a0, const Quantity_Color & a1, const Aspect_GradientFillMethod a2) -> void { return self.SetBgGradientColors(a0, a1, a2); });
cls_V3d_View.def("SetBgGradientColors", (void (V3d_View::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod, const Standard_Boolean)) &V3d_View::SetBgGradientColors, "Defines the gradient background colors of the view by supplying the colors and the fill method (horizontal by default).", py::arg("theColor1"), py::arg("theColor2"), py::arg("theFillStyle"), py::arg("theToUpdate"));
cls_V3d_View.def("SetBgGradientStyle", [](V3d_View &self) -> void { return self.SetBgGradientStyle(); });
cls_V3d_View.def("SetBgGradientStyle", [](V3d_View &self, const Aspect_GradientFillMethod a0) -> void { return self.SetBgGradientStyle(a0); });
cls_V3d_View.def("SetBgGradientStyle", (void (V3d_View::*)(const Aspect_GradientFillMethod, const Standard_Boolean)) &V3d_View::SetBgGradientStyle, "Defines the gradient background fill method of the view.", py::arg("theMethod"), py::arg("theToUpdate"));
cls_V3d_View.def("SetBackgroundImage", [](V3d_View &self, const Standard_CString a0) -> void { return self.SetBackgroundImage(a0); });
cls_V3d_View.def("SetBackgroundImage", [](V3d_View &self, const Standard_CString a0, const Aspect_FillMethod a1) -> void { return self.SetBackgroundImage(a0, a1); });
cls_V3d_View.def("SetBackgroundImage", (void (V3d_View::*)(const Standard_CString, const Aspect_FillMethod, const Standard_Boolean)) &V3d_View::SetBackgroundImage, "Defines the background texture of the view by supplying the texture image file name and fill method (centered by default).", py::arg("theFileName"), py::arg("theFillStyle"), py::arg("theToUpdate"));
cls_V3d_View.def("SetBgImageStyle", [](V3d_View &self, const Aspect_FillMethod a0) -> void { return self.SetBgImageStyle(a0); });
cls_V3d_View.def("SetBgImageStyle", (void (V3d_View::*)(const Aspect_FillMethod, const Standard_Boolean)) &V3d_View::SetBgImageStyle, "Defines the textured background fill method of the view.", py::arg("theFillStyle"), py::arg("theToUpdate"));
cls_V3d_View.def("SetAxis", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::SetAxis, "Definition of an axis from its origin and its orientation . This will be the current axis for rotations and movements. Warning! raises BadValue from V3d if the vector normal is NULL. .", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Vx"), py::arg("Vy"), py::arg("Vz"));
cls_V3d_View.def("SetShadingModel", (void (V3d_View::*)(const Graphic3d_TypeOfShadingModel)) &V3d_View::SetShadingModel, "Defines the shading model for the visualization. Various models are available.", py::arg("theShadingModel"));
cls_V3d_View.def("SetTextureEnv", (void (V3d_View::*)(const opencascade::handle<Graphic3d_TextureEnv> &)) &V3d_View::SetTextureEnv, "Sets the environment texture to use. No environment texture by default.", py::arg("theTexture"));
cls_V3d_View.def("SetVisualization", (void (V3d_View::*)(const V3d_TypeOfVisualization)) &V3d_View::SetVisualization, "Defines the visualization type in the view.", py::arg("theType"));
cls_V3d_View.def("SetLightOn", (void (V3d_View::*)(const opencascade::handle<V3d_Light> &)) &V3d_View::SetLightOn, "Activates theLight in the view.", py::arg("theLight"));
cls_V3d_View.def("SetLightOn", (void (V3d_View::*)()) &V3d_View::SetLightOn, "Activates all the lights defined in this view.");
cls_V3d_View.def("SetLightOff", (void (V3d_View::*)(const opencascade::handle<V3d_Light> &)) &V3d_View::SetLightOff, "Deactivate theLight in this view.", py::arg("theLight"));
cls_V3d_View.def("SetLightOff", (void (V3d_View::*)()) &V3d_View::SetLightOff, "Deactivate all the Lights defined in this view.");
cls_V3d_View.def("IsActiveLight", (Standard_Boolean (V3d_View::*)(const opencascade::handle<V3d_Light> &) const) &V3d_View::IsActiveLight, "Returns TRUE when the light is active in this view.", py::arg("theLight"));
cls_V3d_View.def("SetImmediateUpdate", (Standard_Boolean (V3d_View::*)(const Standard_Boolean)) &V3d_View::SetImmediateUpdate, "sets the immediate update mode and returns the previous one.", py::arg("theImmediateUpdate"));
cls_V3d_View.def("ZBufferTriedronSetup", [](V3d_View &self) -> void { return self.ZBufferTriedronSetup(); });
cls_V3d_View.def("ZBufferTriedronSetup", [](V3d_View &self, const Quantity_Color & a0) -> void { return self.ZBufferTriedronSetup(a0); });
cls_V3d_View.def("ZBufferTriedronSetup", [](V3d_View &self, const Quantity_Color & a0, const Quantity_Color & a1) -> void { return self.ZBufferTriedronSetup(a0, a1); });
cls_V3d_View.def("ZBufferTriedronSetup", [](V3d_View &self, const Quantity_Color & a0, const Quantity_Color & a1, const Quantity_Color & a2) -> void { return self.ZBufferTriedronSetup(a0, a1, a2); });
cls_V3d_View.def("ZBufferTriedronSetup", [](V3d_View &self, const Quantity_Color & a0, const Quantity_Color & a1, const Quantity_Color & a2, const Standard_Real a3) -> void { return self.ZBufferTriedronSetup(a0, a1, a2, a3); });
cls_V3d_View.def("ZBufferTriedronSetup", [](V3d_View &self, const Quantity_Color & a0, const Quantity_Color & a1, const Quantity_Color & a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.ZBufferTriedronSetup(a0, a1, a2, a3, a4); });
cls_V3d_View.def("ZBufferTriedronSetup", (void (V3d_View::*)(const Quantity_Color &, const Quantity_Color &, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Integer)) &V3d_View::ZBufferTriedronSetup, "Customization of the ZBUFFER Triedron. XColor,YColor,ZColor - colors of axis SizeRatio - ratio of decreasing of the trihedron size when its physical position comes out of the view AxisDiametr - diameter relatively to axis length NbFacettes - number of facets of cylinders and cones", py::arg("theXColor"), py::arg("theYColor"), py::arg("theZColor"), py::arg("theSizeRatio"), py::arg("theAxisDiametr"), py::arg("theNbFacettes"));
cls_V3d_View.def("TriedronDisplay", [](V3d_View &self) -> void { return self.TriedronDisplay(); });
cls_V3d_View.def("TriedronDisplay", [](V3d_View &self, const Aspect_TypeOfTriedronPosition a0) -> void { return self.TriedronDisplay(a0); });
cls_V3d_View.def("TriedronDisplay", [](V3d_View &self, const Aspect_TypeOfTriedronPosition a0, const Quantity_Color & a1) -> void { return self.TriedronDisplay(a0, a1); });
cls_V3d_View.def("TriedronDisplay", [](V3d_View &self, const Aspect_TypeOfTriedronPosition a0, const Quantity_Color & a1, const Standard_Real a2) -> void { return self.TriedronDisplay(a0, a1, a2); });
cls_V3d_View.def("TriedronDisplay", (void (V3d_View::*)(const Aspect_TypeOfTriedronPosition, const Quantity_Color &, const Standard_Real, const V3d_TypeOfVisualization)) &V3d_View::TriedronDisplay, "Display of the Triedron. Initialize position, color and length of Triedron axes. The scale is a percent of the window width.", py::arg("thePosition"), py::arg("theColor"), py::arg("theScale"), py::arg("theMode"));
cls_V3d_View.def("TriedronErase", (void (V3d_View::*)()) &V3d_View::TriedronErase, "Erases the Triedron.");
cls_V3d_View.def("GetGraduatedTrihedron", (const Graphic3d_GraduatedTrihedron & (V3d_View::*)() const) &V3d_View::GetGraduatedTrihedron, "Returns data of a graduated trihedron.");
cls_V3d_View.def("GraduatedTrihedronDisplay", (void (V3d_View::*)(const Graphic3d_GraduatedTrihedron &)) &V3d_View::GraduatedTrihedronDisplay, "Displays a graduated trihedron.", py::arg("theTrihedronData"));
cls_V3d_View.def("GraduatedTrihedronErase", (void (V3d_View::*)()) &V3d_View::GraduatedTrihedronErase, "Erases a graduated trihedron from the view.");
cls_V3d_View.def("SetFront", (void (V3d_View::*)()) &V3d_View::SetFront, "modify the Projection of the view perpendicularly to the privileged plane of the viewer.");
cls_V3d_View.def("Rotate", [](V3d_View &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Rotate(a0, a1, a2); });
cls_V3d_View.def("Rotate", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &V3d_View::Rotate, "Rotates the eye about the coordinate system of reference of the screen for which the origin is the view point of the projection, with a relative angular value in RADIANS with respect to the initial position expressed by Start = Standard_True Warning! raises BadValue from V3d If the eye, the view point, or the high point are aligned or confused.", py::arg("Ax"), py::arg("Ay"), py::arg("Az"), py::arg("Start"));
cls_V3d_View.def("Rotate", [](V3d_View &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4, const Standard_Real a5) -> void { return self.Rotate(a0, a1, a2, a3, a4, a5); });
cls_V3d_View.def("Rotate", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &V3d_View::Rotate, "Rotates the eye about the coordinate system of reference of the screen for which the origin is Gravity point {X,Y,Z}, with a relative angular value in RADIANS with respect to the initial position expressed by Start = Standard_True If the eye, the view point, or the high point are aligned or confused.", py::arg("Ax"), py::arg("Ay"), py::arg("Az"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Start"));
cls_V3d_View.def("Rotate", [](V3d_View &self, const V3d_TypeOfAxe a0, const Standard_Real a1, const Standard_Real a2, const Standard_Real a3, const Standard_Real a4) -> void { return self.Rotate(a0, a1, a2, a3, a4); });
cls_V3d_View.def("Rotate", (void (V3d_View::*)(const V3d_TypeOfAxe, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &V3d_View::Rotate, "Rotates the eye about one of the coordinate axes of of the view for which the origin is the Gravity point{X,Y,Z} with an relative angular value in RADIANS with respect to the initial position expressed by Start = Standard_True", py::arg("Axe"), py::arg("Angle"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Start"));
cls_V3d_View.def("Rotate", [](V3d_View &self, const V3d_TypeOfAxe a0, const Standard_Real a1) -> void { return self.Rotate(a0, a1); });
cls_V3d_View.def("Rotate", (void (V3d_View::*)(const V3d_TypeOfAxe, const Standard_Real, const Standard_Boolean)) &V3d_View::Rotate, "Rotates the eye about one of the coordinate axes of of the view for which the origin is the view point of the projection with an relative angular value in RADIANS with respect to the initial position expressed by Start = Standard_True", py::arg("Axe"), py::arg("Angle"), py::arg("Start"));
cls_V3d_View.def("Rotate", [](V3d_View &self, const Standard_Real a0) -> void { return self.Rotate(a0); });
cls_V3d_View.def("Rotate", (void (V3d_View::*)(const Standard_Real, const Standard_Boolean)) &V3d_View::Rotate, "Rotates the eye around the current axis a relative angular value in RADIANS with respect to the initial position expressed by Start = Standard_True", py::arg("Angle"), py::arg("Start"));
cls_V3d_View.def("Move", [](V3d_View &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Move(a0, a1, a2); });
cls_V3d_View.def("Move", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &V3d_View::Move, "Movement of the eye parallel to the coordinate system of reference of the screen a distance relative to the initial position expressed by Start = Standard_True.", py::arg("Dx"), py::arg("Dy"), py::arg("Dz"), py::arg("Start"));
cls_V3d_View.def("Move", [](V3d_View &self, const V3d_TypeOfAxe a0, const Standard_Real a1) -> void { return self.Move(a0, a1); });
cls_V3d_View.def("Move", (void (V3d_View::*)(const V3d_TypeOfAxe, const Standard_Real, const Standard_Boolean)) &V3d_View::Move, "Movement of the eye parallel to one of the axes of the coordinate system of reference of the view a distance relative to the initial position expressed by Start = Standard_True.", py::arg("Axe"), py::arg("Length"), py::arg("Start"));
cls_V3d_View.def("Move", [](V3d_View &self, const Standard_Real a0) -> void { return self.Move(a0); });
cls_V3d_View.def("Move", (void (V3d_View::*)(const Standard_Real, const Standard_Boolean)) &V3d_View::Move, "Movement of the eye parllel to the current axis a distance relative to the initial position expressed by Start = Standard_True", py::arg("Length"), py::arg("Start"));
cls_V3d_View.def("Translate", [](V3d_View &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Translate(a0, a1, a2); });
cls_V3d_View.def("Translate", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &V3d_View::Translate, "Movement of the ye and the view point parallel to the frame of reference of the screen a distance relative to the initial position expressed by Start = Standard_True", py::arg("Dx"), py::arg("Dy"), py::arg("Dz"), py::arg("Start"));
cls_V3d_View.def("Translate", [](V3d_View &self, const V3d_TypeOfAxe a0, const Standard_Real a1) -> void { return self.Translate(a0, a1); });
cls_V3d_View.def("Translate", (void (V3d_View::*)(const V3d_TypeOfAxe, const Standard_Real, const Standard_Boolean)) &V3d_View::Translate, "Movement of the eye and the view point parallel to one of the axes of the fame of reference of the view a distance relative to the initial position expressed by Start = Standard_True", py::arg("Axe"), py::arg("Length"), py::arg("Start"));
cls_V3d_View.def("Translate", [](V3d_View &self, const Standard_Real a0) -> void { return self.Translate(a0); });
cls_V3d_View.def("Translate", (void (V3d_View::*)(const Standard_Real, const Standard_Boolean)) &V3d_View::Translate, "Movement of the eye and view point parallel to the current axis a distance relative to the initial position expressed by Start = Standard_True", py::arg("Length"), py::arg("Start"));
cls_V3d_View.def("Place", [](V3d_View &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Place(a0, a1); });
cls_V3d_View.def("Place", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &V3d_View::Place, "places the point of the view corresponding at the pixel position x,y at the center of the window and updates the view.", py::arg("theXp"), py::arg("theYp"), py::arg("theZoomFactor"));
cls_V3d_View.def("Turn", [](V3d_View &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Turn(a0, a1, a2); });
cls_V3d_View.def("Turn", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &V3d_View::Turn, "Rotation of the view point around the frame of reference of the screen for which the origin is the eye of the projection with a relative angular value in RADIANS with respect to the initial position expressed by Start = Standard_True", py::arg("Ax"), py::arg("Ay"), py::arg("Az"), py::arg("Start"));
cls_V3d_View.def("Turn", [](V3d_View &self, const V3d_TypeOfAxe a0, const Standard_Real a1) -> void { return self.Turn(a0, a1); });
cls_V3d_View.def("Turn", (void (V3d_View::*)(const V3d_TypeOfAxe, const Standard_Real, const Standard_Boolean)) &V3d_View::Turn, "Rotation of the view point around one of the axes of the frame of reference of the view for which the origin is the eye of the projection with an angular value in RADIANS relative to the initial position expressed by Start = Standard_True", py::arg("Axe"), py::arg("Angle"), py::arg("Start"));
cls_V3d_View.def("Turn", [](V3d_View &self, const Standard_Real a0) -> void { return self.Turn(a0); });
cls_V3d_View.def("Turn", (void (V3d_View::*)(const Standard_Real, const Standard_Boolean)) &V3d_View::Turn, "Rotation of the view point around the current axis an angular value in RADIANS relative to the initial position expressed by Start = Standard_True", py::arg("Angle"), py::arg("Start"));
cls_V3d_View.def("SetTwist", (void (V3d_View::*)(const Standard_Real)) &V3d_View::SetTwist, "Defines the angular position of the high point of the reference frame of the view with respect to the Y screen axis with an absolute angular value in RADIANS.", py::arg("Angle"));
cls_V3d_View.def("SetEye", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::SetEye, "Defines the position of the eye..", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_V3d_View.def("SetDepth", (void (V3d_View::*)(const Standard_Real)) &V3d_View::SetDepth, "Defines the Depth of the eye from the view point without update the projection .", py::arg("Depth"));
cls_V3d_View.def("SetProj", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::SetProj, "Defines the orientation of the projection.", py::arg("Vx"), py::arg("Vy"), py::arg("Vz"));
cls_V3d_View.def("SetProj", (void (V3d_View::*)(const V3d_TypeOfOrientation)) &V3d_View::SetProj, "Defines the orientation of the projection .", py::arg("Orientation"));
cls_V3d_View.def("SetAt", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::SetAt, "Defines the position of the view point.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_V3d_View.def("SetUp", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::SetUp, "Defines the orientation of the high point.", py::arg("Vx"), py::arg("Vy"), py::arg("Vz"));
cls_V3d_View.def("SetUp", (void (V3d_View::*)(const V3d_TypeOfOrientation)) &V3d_View::SetUp, "Defines the orientation(SO) of the high point.", py::arg("Orientation"));
cls_V3d_View.def("SetViewOrientationDefault", (void (V3d_View::*)()) &V3d_View::SetViewOrientationDefault, "Saves the current state of the orientation of the view which will be the return state at ResetViewOrientation.");
cls_V3d_View.def("ResetViewOrientation", (void (V3d_View::*)()) &V3d_View::ResetViewOrientation, "Resets the orientation of the view. Updates the view");
cls_V3d_View.def("Panning", [](V3d_View &self, const Standard_Real a0, const Standard_Real a1) -> void { return self.Panning(a0, a1); });
cls_V3d_View.def("Panning", [](V3d_View &self, const Standard_Real a0, const Standard_Real a1, const Standard_Real a2) -> void { return self.Panning(a0, a1, a2); });
cls_V3d_View.def("Panning", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean)) &V3d_View::Panning, "Translates the center of the view along 'x' and 'y' axes of view projection. Can be used to perform interactive panning operation. In that case the DXv, DXy parameters specify panning relative to the point where the operation is started.", py::arg("theDXv"), py::arg("theDYv"), py::arg("theZoomFactor"), py::arg("theToStart"));
cls_V3d_View.def("SetCenter", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer)) &V3d_View::SetCenter, "Relocates center of screen to the point, determined by {Xp, Yp} pixel coordinates relative to the bottom-left corner of screen. To calculate pixel coordinates for any point from world coordinate space, it can be projected using 'Project'.", py::arg("theXp"), py::arg("theYp"));
cls_V3d_View.def("SetSize", (void (V3d_View::*)(const Standard_Real)) &V3d_View::SetSize, "Defines the view projection size in its maximum dimension, keeping the inital height/width ratio unchanged.", py::arg("theSize"));
cls_V3d_View.def("SetZSize", (void (V3d_View::*)(const Standard_Real)) &V3d_View::SetZSize, "Defines the Depth size of the view Front Plane will be set to Size/2. Back Plane will be set to -Size/2. Any Object located Above the Front Plane or behind the Back Plane will be Clipped . NOTE than the XY Size of the View is NOT modified .", py::arg("SetZSize"));
cls_V3d_View.def("SetZoom", [](V3d_View &self, const Standard_Real a0) -> void { return self.SetZoom(a0); });
cls_V3d_View.def("SetZoom", (void (V3d_View::*)(const Standard_Real, const Standard_Boolean)) &V3d_View::SetZoom, "Zooms the view by a factor relative to the initial value expressed by Start = Standard_True Updates the view.", py::arg("Coef"), py::arg("Start"));
cls_V3d_View.def("SetScale", (void (V3d_View::*)(const Standard_Real)) &V3d_View::SetScale, "Zooms the view by a factor relative to the value initialised by SetViewMappingDefault(). Updates the view.", py::arg("Coef"));
cls_V3d_View.def("SetAxialScale", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::SetAxialScale, "Sets anisotropic (axial) scale factors <Sx>, <Sy>, <Sz> for view <me>. Anisotropic scaling operation is performed through multiplying the current view orientation matrix by a scaling matrix: || Sx 0 0 0 || || 0 Sy 0 0 || || 0 0 Sz 0 || || 0 0 0 1 || Updates the view.", py::arg("Sx"), py::arg("Sy"), py::arg("Sz"));
cls_V3d_View.def("FitAll", [](V3d_View &self) -> void { return self.FitAll(); });
cls_V3d_View.def("FitAll", [](V3d_View &self, const Standard_Real a0) -> void { return self.FitAll(a0); });
cls_V3d_View.def("FitAll", (void (V3d_View::*)(const Standard_Real, const Standard_Boolean)) &V3d_View::FitAll, "Adjust view parameters to fit the displayed scene, respecting height / width ratio. The Z clipping range (depth range) is fitted if AutoZFit flag is TRUE. Throws program error exception if margin coefficient is < 0 or >= 1. Updates the view.", py::arg("theMargin"), py::arg("theToUpdate"));
cls_V3d_View.def("FitAll", [](V3d_View &self, const Bnd_Box & a0) -> void { return self.FitAll(a0); });
cls_V3d_View.def("FitAll", [](V3d_View &self, const Bnd_Box & a0, const Standard_Real a1) -> void { return self.FitAll(a0, a1); });
cls_V3d_View.def("FitAll", (void (V3d_View::*)(const Bnd_Box &, const Standard_Real, const Standard_Boolean)) &V3d_View::FitAll, "Adjust view parameters to fit the displayed scene, respecting height / width ratio according to the custom bounding box given. Throws program error exception if margin coefficient is < 0 or >= 1. Updates the view.", py::arg("theBox"), py::arg("theMargin"), py::arg("theToUpdate"));
cls_V3d_View.def("DepthFitAll", [](V3d_View &self) -> void { return self.DepthFitAll(); });
cls_V3d_View.def("DepthFitAll", [](V3d_View &self, const Standard_Real a0) -> void { return self.DepthFitAll(a0); });
cls_V3d_View.def("DepthFitAll", (void (V3d_View::*)(const Standard_Real, const Standard_Real)) &V3d_View::DepthFitAll, "Adjusts the viewing volume so as not to clip the displayed objects by front and back and back clipping planes. Also sets depth value automatically depending on the calculated Z size and Aspect parameter. NOTE than the original XY size of the view is NOT modified .", py::arg("Aspect"), py::arg("Margin"));
cls_V3d_View.def("FitAll", (void (V3d_View::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_View::FitAll, "Centers the defined projection window so that it occupies the maximum space while respecting the initial height/width ratio. NOTE than the original Z size of the view is NOT modified .", py::arg("theMinXv"), py::arg("theMinYv"), py::arg("theMaxXv"), py::arg("theMaxYv"));
cls_V3d_View.def("WindowFit", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &V3d_View::WindowFit, "Centers the defined PIXEL window so that it occupies the maximum space while respecting the initial height/width ratio. NOTE than the original Z size of the view is NOT modified.", py::arg("theMinXp"), py::arg("theMinYp"), py::arg("theMaxXp"), py::arg("theMaxYp"));
cls_V3d_View.def("SetViewMappingDefault", (void (V3d_View::*)()) &V3d_View::SetViewMappingDefault, "Saves the current view mapping. This will be the state returned from ResetViewmapping.");
cls_V3d_View.def("ResetViewMapping", (void (V3d_View::*)()) &V3d_View::ResetViewMapping, "Resets the centering of the view. Updates the view");
cls_V3d_View.def("Reset", [](V3d_View &self) -> void { return self.Reset(); });
cls_V3d_View.def("Reset", (void (V3d_View::*)(const Standard_Boolean)) &V3d_View::Reset, "Resets the centering and the orientation of the view.", py::arg("theToUpdate"));
cls_V3d_View.def("Convert", (Standard_Real (V3d_View::*)(const Standard_Integer) const) &V3d_View::Convert, "Converts the PIXEL value to a value in the projection plane.", py::arg("Vp"));
cls_V3d_View.def("Convert", [](V3d_View &self, const Standard_Integer Xp, const Standard_Integer Yp, Standard_Real & Xv, Standard_Real & Yv){ self.Convert(Xp, Yp, Xv, Yv); return std::tuple<Standard_Real &, Standard_Real &>(Xv, Yv); }, "Converts the point PIXEL into a point projected in the reference frame of the projection plane.", py::arg("Xp"), py::arg("Yp"), py::arg("Xv"), py::arg("Yv"));
cls_V3d_View.def("Convert", (Standard_Integer (V3d_View::*)(const Standard_Real) const) &V3d_View::Convert, "Converts tha value of the projection plane into a PIXEL value.", py::arg("Vv"));
cls_V3d_View.def("Convert", [](V3d_View &self, const Standard_Real Xv, const Standard_Real Yv, Standard_Integer & Xp, Standard_Integer & Yp){ self.Convert(Xv, Yv, Xp, Yp); return std::tuple<Standard_Integer &, Standard_Integer &>(Xp, Yp); }, "Converts the point defined in the reference frame of the projection plane into a point PIXEL.", py::arg("Xv"), py::arg("Yv"), py::arg("Xp"), py::arg("Yp"));
cls_V3d_View.def("Convert", [](V3d_View &self, const Standard_Integer Xp, const Standard_Integer Yp, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Convert(Xp, Yp, X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Converts the projected point into a point in the reference frame of the view corresponding to the intersection with the projection plane of the eye/view point vector.", py::arg("Xp"), py::arg("Yp"), py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_V3d_View.def("ConvertWithProj", [](V3d_View &self, const Standard_Integer Xp, const Standard_Integer Yp, Standard_Real & X, Standard_Real & Y, Standard_Real & Z, Standard_Real & Vx, Standard_Real & Vy, Standard_Real & Vz){ self.ConvertWithProj(Xp, Yp, X, Y, Z, Vx, Vy, Vz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z, Vx, Vy, Vz); }, "Converts the projected point into a point in the reference frame of the view corresponding to the intersection with the projection plane of the eye/view point vector and returns the projection ray for further computations.", py::arg("Xp"), py::arg("Yp"), py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Vx"), py::arg("Vy"), py::arg("Vz"));
cls_V3d_View.def("ConvertToGrid", [](V3d_View &self, const Standard_Integer Xp, const Standard_Integer Yp, Standard_Real & Xg, Standard_Real & Yg, Standard_Real & Zg){ self.ConvertToGrid(Xp, Yp, Xg, Yg, Zg); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xg, Yg, Zg); }, "Converts the projected point into the nearest grid point in the reference frame of the view corresponding to the intersection with the projection plane of the eye/view point vector and display the grid marker. Warning: When the grid is not active the result is identical to the above Convert() method. How to use: 1) Enable the grid echo display myViewer->SetGridEcho(Standard_True); 2) When application receive a move event: 2.1) Check if any object is detected if( myInteractiveContext->MoveTo(x,y) == AIS_SOD_Nothing ) { 2.2) Check if the grid is active if( myViewer->Grid()->IsActive() ) { 2.3) Display the grid echo and gets the grid point myView->ConvertToGrid(x,y,X,Y,Z); myView->Viewer()->ShowGridEcho (myView, Graphic3d_Vertex (X,Y,Z)); myView->RedrawImmediate(); 2.4) Else this is the standard case } else myView->Convert(x,y,X,Y,Z);", py::arg("Xp"), py::arg("Yp"), py::arg("Xg"), py::arg("Yg"), py::arg("Zg"));
cls_V3d_View.def("ConvertToGrid", [](V3d_View &self, const Standard_Real X, const Standard_Real Y, const Standard_Real Z, Standard_Real & Xg, Standard_Real & Yg, Standard_Real & Zg){ self.ConvertToGrid(X, Y, Z, Xg, Yg, Zg); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Xg, Yg, Zg); }, "Converts the point into the nearest grid point and display the grid marker.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Xg"), py::arg("Yg"), py::arg("Zg"));
cls_V3d_View.def("Convert", [](V3d_View &self, const Standard_Real X, const Standard_Real Y, const Standard_Real Z, Standard_Integer & Xp, Standard_Integer & Yp){ self.Convert(X, Y, Z, Xp, Yp); return std::tuple<Standard_Integer &, Standard_Integer &>(Xp, Yp); }, "Projects the point defined in the reference frame of the view into the projected point in the associated window.", py::arg("X"), py::arg("Y"), py::arg("Z"), py::arg("Xp"), py::arg("Yp"));
cls_V3d_View.def("Project", [](V3d_View &self, const Standard_Real theX, const Standard_Real theY, const Standard_Real theZ, Standard_Real & theXp, Standard_Real & theYp){ self.Project(theX, theY, theZ, theXp, theYp); return std::tuple<Standard_Real &, Standard_Real &>(theXp, theYp); }, "Converts the point defined in the user space of the view to the projection plane at the depth relative to theZ.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theXp"), py::arg("theYp"));
cls_V3d_View.def("Project", [](V3d_View &self, const Standard_Real theX, const Standard_Real theY, const Standard_Real theZ, Standard_Real & theXp, Standard_Real & theYp, Standard_Real & theZp){ self.Project(theX, theY, theZ, theXp, theYp, theZp); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theXp, theYp, theZp); }, "Converts the point defined in the user space of the view to the projection plane at the depth relative to theZ.", py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"));
cls_V3d_View.def("BackgroundColor", [](V3d_View &self, const Quantity_TypeOfColor Type, Standard_Real & V1, Standard_Real & V2, Standard_Real & V3){ self.BackgroundColor(Type, V1, V2, V3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(V1, V2, V3); }, "Returns the Background color values of the view depending of the color Type.", py::arg("Type"), py::arg("V1"), py::arg("V2"), py::arg("V3"));
cls_V3d_View.def("BackgroundColor", (Quantity_Color (V3d_View::*)() const) &V3d_View::BackgroundColor, "Returns the Background color object of the view.");
cls_V3d_View.def("GradientBackgroundColors", (void (V3d_View::*)(Quantity_Color &, Quantity_Color &) const) &V3d_View::GradientBackgroundColors, "Returns the gradient background colors of the view.", py::arg("theColor1"), py::arg("theColor2"));
cls_V3d_View.def("GradientBackground", (Aspect_GradientBackground (V3d_View::*)() const) &V3d_View::GradientBackground, "Returns the gradient background of the view.");
cls_V3d_View.def("Scale", (Standard_Real (V3d_View::*)() const) &V3d_View::Scale, "Returns the current value of the zoom expressed with respect to SetViewMappingDefault().");
cls_V3d_View.def("AxialScale", [](V3d_View &self, Standard_Real & Sx, Standard_Real & Sy, Standard_Real & Sz){ self.AxialScale(Sx, Sy, Sz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Sx, Sy, Sz); }, "Returns the current values of the anisotropic (axial) scale factors.", py::arg("Sx"), py::arg("Sy"), py::arg("Sz"));
cls_V3d_View.def("Size", [](V3d_View &self, Standard_Real & Width, Standard_Real & Height){ self.Size(Width, Height); return std::tuple<Standard_Real &, Standard_Real &>(Width, Height); }, "Returns the height and width of the view.", py::arg("Width"), py::arg("Height"));
cls_V3d_View.def("ZSize", (Standard_Real (V3d_View::*)() const) &V3d_View::ZSize, "Returns the Depth of the view .");
cls_V3d_View.def("Eye", [](V3d_View &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Eye(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Returns the position of the eye.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_V3d_View.def("FocalReferencePoint", [](V3d_View &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.FocalReferencePoint(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Returns the position of point which emanating the projections.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_V3d_View.def("ProjReferenceAxe", [](V3d_View &self, const Standard_Integer Xpix, const Standard_Integer Ypix, Standard_Real & XP, Standard_Real & YP, Standard_Real & ZP, Standard_Real & VX, Standard_Real & VY, Standard_Real & VZ){ self.ProjReferenceAxe(Xpix, Ypix, XP, YP, ZP, VX, VY, VZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(XP, YP, ZP, VX, VY, VZ); }, "Returns the coordinate of the point (Xpix,Ypix) in the view (XP,YP,ZP), and the projection vector of the view passing by the point (for PerspectiveView).", py::arg("Xpix"), py::arg("Ypix"), py::arg("XP"), py::arg("YP"), py::arg("ZP"), py::arg("VX"), py::arg("VY"), py::arg("VZ"));
cls_V3d_View.def("Depth", (Standard_Real (V3d_View::*)() const) &V3d_View::Depth, "Returns the Distance between the Eye and View Point.");
cls_V3d_View.def("Proj", [](V3d_View &self, Standard_Real & Vx, Standard_Real & Vy, Standard_Real & Vz){ self.Proj(Vx, Vy, Vz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Vx, Vy, Vz); }, "Returns the projection vector.", py::arg("Vx"), py::arg("Vy"), py::arg("Vz"));
cls_V3d_View.def("At", [](V3d_View &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.At(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "Returns the position of the view point.", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_V3d_View.def("Up", [](V3d_View &self, Standard_Real & Vx, Standard_Real & Vy, Standard_Real & Vz){ self.Up(Vx, Vy, Vz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(Vx, Vy, Vz); }, "Returns the vector giving the position of the high point.", py::arg("Vx"), py::arg("Vy"), py::arg("Vz"));
cls_V3d_View.def("Twist", (Standard_Real (V3d_View::*)() const) &V3d_View::Twist, "Returns in RADIANS the orientation of the view around the visual axis measured from the Y axis of the screen.");
cls_V3d_View.def("ShadingModel", (Graphic3d_TypeOfShadingModel (V3d_View::*)() const) &V3d_View::ShadingModel, "Returns the current shading model.");
cls_V3d_View.def("TextureEnv", (opencascade::handle<Graphic3d_TextureEnv> (V3d_View::*)() const) &V3d_View::TextureEnv, "None");
cls_V3d_View.def("Visualization", (V3d_TypeOfVisualization (V3d_View::*)() const) &V3d_View::Visualization, "Returns the current visualisation mode.");
cls_V3d_View.def("IfMoreLights", (Standard_Boolean (V3d_View::*)() const) &V3d_View::IfMoreLights, "Returns True if One light more can be activated in this View.");
cls_V3d_View.def("ActiveLightIterator", (V3d_ListOfLightIterator (V3d_View::*)() const) &V3d_View::ActiveLightIterator, "Return iterator for defined lights.");
cls_V3d_View.def("InitActiveLights", (void (V3d_View::*)()) &V3d_View::InitActiveLights, "initializes an iteration on the active Lights.");
cls_V3d_View.def("MoreActiveLights", (Standard_Boolean (V3d_View::*)() const) &V3d_View::MoreActiveLights, "returns true if there are more active Light(s) to return.");
cls_V3d_View.def("NextActiveLights", (void (V3d_View::*)()) &V3d_View::NextActiveLights, "Go to the next active Light (if there is not, ActiveLight will raise an exception)");
cls_V3d_View.def("ActiveLight", (const opencascade::handle<V3d_Light> & (V3d_View::*)() const) &V3d_View::ActiveLight, "None");
cls_V3d_View.def("LightLimit", (Standard_Integer (V3d_View::*)() const) &V3d_View::LightLimit, "Returns the MAX number of light associated to the view.");
cls_V3d_View.def("Viewer", (opencascade::handle<V3d_Viewer> (V3d_View::*)() const) &V3d_View::Viewer, "Returns the viewer in which the view has been created.");
cls_V3d_View.def("IfWindow", (Standard_Boolean (V3d_View::*)() const) &V3d_View::IfWindow, "Returns True if MyView is associated with a window .");
cls_V3d_View.def("Window", (opencascade::handle<Aspect_Window> (V3d_View::*)() const) &V3d_View::Window, "Returns the Aspect Window associated with the view.");
cls_V3d_View.def("Type", (V3d_TypeOfView (V3d_View::*)() const) &V3d_View::Type, "Returns the Type of the View");
cls_V3d_View.def("Pan", [](V3d_View &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.Pan(a0, a1); });
cls_V3d_View.def("Pan", [](V3d_View &self, const Standard_Integer a0, const Standard_Integer a1, const Standard_Real a2) -> void { return self.Pan(a0, a1, a2); });
cls_V3d_View.def("Pan", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Real, const Standard_Boolean)) &V3d_View::Pan, "Translates the center of the view along 'x' and 'y' axes of view projection. Can be used to perform interactive panning operation. In that case the DXp, DXp parameters specify panning relative to the point where the operation is started.", py::arg("theDXp"), py::arg("theDYp"), py::arg("theZoomFactor"), py::arg("theToStart"));
cls_V3d_View.def("Zoom", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &V3d_View::Zoom, "Zoom the view according to a zoom factor computed from the distance between the 2 mouse position.", py::arg("theXp1"), py::arg("theYp1"), py::arg("theXp2"), py::arg("theYp2"));
cls_V3d_View.def("StartZoomAtPoint", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer)) &V3d_View::StartZoomAtPoint, "Defines starting point for ZoomAtPoint view operation.", py::arg("theXp"), py::arg("theYp"));
cls_V3d_View.def("ZoomAtPoint", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &V3d_View::ZoomAtPoint, "Zooms the model at a pixel defined by the method StartZoomAtPoint().", py::arg("theMouseStartX"), py::arg("theMouseStartY"), py::arg("theMouseEndX"), py::arg("theMouseEndY"));
cls_V3d_View.def("AxialScale", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const V3d_TypeOfAxe)) &V3d_View::AxialScale, "Performs anisotropic scaling of <me> view along the given <Axis>. The scale factor is calculated on a basis of the mouse pointer displacement <Dx,Dy>. The calculated scale factor is then passed to SetAxialScale(Sx, Sy, Sz) method.", py::arg("Dx"), py::arg("Dy"), py::arg("Axis"));
cls_V3d_View.def("StartRotation", [](V3d_View &self, const Standard_Integer a0, const Standard_Integer a1) -> void { return self.StartRotation(a0, a1); });
cls_V3d_View.def("StartRotation", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Real)) &V3d_View::StartRotation, "Begin the rotation of the view around the screen axis according to the mouse position <X,Y>. Warning: Enable rotation around the Z screen axis when <zRotationThreshold> factor is > 0 soon the distance from the start point and the center of the view is > (medium viewSize * <zRotationThreshold> ). Generally a value of 0.4 is usable to rotate around XY screen axis inside the circular threshold area and to rotate around Z screen axis outside this area.", py::arg("X"), py::arg("Y"), py::arg("zRotationThreshold"));
cls_V3d_View.def("Rotation", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer)) &V3d_View::Rotation, "Continues the rotation of the view with an angle computed from the last and new mouse position <X,Y>.", py::arg("X"), py::arg("Y"));
cls_V3d_View.def("SetFocale", (void (V3d_View::*)(const Standard_Real)) &V3d_View::SetFocale, "Change View Plane Distance for Perspective Views Warning! raises TypeMismatch from Standard if the view is not a perspective view.", py::arg("Focale"));
cls_V3d_View.def("Focale", (Standard_Real (V3d_View::*)() const) &V3d_View::Focale, "Returns the View Plane Distance for Perspective Views");
cls_V3d_View.def("View", (opencascade::handle<Graphic3d_CView> (V3d_View::*)() const) &V3d_View::View, "Returns the associated Graphic3d view.");
cls_V3d_View.def("SetComputedMode", (void (V3d_View::*)(const Standard_Boolean)) &V3d_View::SetComputedMode, "Switches computed HLR mode in the view.", py::arg("theMode"));
cls_V3d_View.def("ComputedMode", (Standard_Boolean (V3d_View::*)() const) &V3d_View::ComputedMode, "Returns the computed HLR mode state.");
cls_V3d_View.def("WindowFitAll", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &V3d_View::WindowFitAll, "idem than WindowFit", py::arg("Xmin"), py::arg("Ymin"), py::arg("Xmax"), py::arg("Ymax"));
cls_V3d_View.def("SetGrid", (void (V3d_View::*)(const gp_Ax3 &, const opencascade::handle<Aspect_Grid> &)) &V3d_View::SetGrid, "Defines or Updates the definition of the grid in <me>", py::arg("aPlane"), py::arg("aGrid"));
cls_V3d_View.def("SetGridActivity", (void (V3d_View::*)(const Standard_Boolean)) &V3d_View::SetGridActivity, "Defines or Updates the activity of the grid in <me>", py::arg("aFlag"));
cls_V3d_View.def("Dump", [](V3d_View &self, const Standard_CString a0) -> Standard_Boolean { return self.Dump(a0); });
cls_V3d_View.def("Dump", (Standard_Boolean (V3d_View::*)(const Standard_CString, const Graphic3d_BufferType &)) &V3d_View::Dump, "dump the full contents of the view at the same scale in the file <theFile>. The file name extension must be one of '.png','.bmp','.jpg','.gif'. Returns FALSE when the dump has failed", py::arg("theFile"), py::arg("theBufferType"));
cls_V3d_View.def("Export", [](V3d_View &self, const Standard_CString a0, const Graphic3d_ExportFormat a1) -> Standard_Boolean { return self.Export(a0, a1); });
cls_V3d_View.def("Export", (Standard_Boolean (V3d_View::*)(const Standard_CString, const Graphic3d_ExportFormat, const Graphic3d_SortType)) &V3d_View::Export, "Export scene into the one of the Vector graphics formats (SVG, PS, PDF...). In contrast to Bitmaps, Vector graphics is scalable (so you may got quality benefits on printing to laser printer). Notice however that results may differ a lot and do not contain some elements.", py::arg("theFileName"), py::arg("theFormat"), py::arg("theSortType"));
cls_V3d_View.def("ToPixMap", (Standard_Boolean (V3d_View::*)(Image_PixMap &, const V3d_ImageDumpOptions &)) &V3d_View::ToPixMap, "Dumps the full contents of the view to a pixmap with specified parameters.", py::arg("theImage"), py::arg("theParams"));
cls_V3d_View.def("ToPixMap", [](V3d_View &self, Image_PixMap & a0, const Standard_Integer a1, const Standard_Integer a2) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2); });
cls_V3d_View.def("ToPixMap", [](V3d_View &self, Image_PixMap & a0, const Standard_Integer a1, const Standard_Integer a2, const Graphic3d_BufferType & a3) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2, a3); });
cls_V3d_View.def("ToPixMap", [](V3d_View &self, Image_PixMap & a0, const Standard_Integer a1, const Standard_Integer a2, const Graphic3d_BufferType & a3, const Standard_Boolean a4) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2, a3, a4); });
cls_V3d_View.def("ToPixMap", (Standard_Boolean (V3d_View::*)(Image_PixMap &, const Standard_Integer, const Standard_Integer, const Graphic3d_BufferType &, const Standard_Boolean, const V3d_StereoDumpOptions)) &V3d_View::ToPixMap, "Dumps the full contents of the view to a pixmap.", py::arg("theImage"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theBufferType"), py::arg("theToAdjustAspect"), py::arg("theStereoOptions"));
cls_V3d_View.def("SetBackFacingModel", [](V3d_View &self) -> void { return self.SetBackFacingModel(); });
cls_V3d_View.def("SetBackFacingModel", (void (V3d_View::*)(const V3d_TypeOfBackfacingModel)) &V3d_View::SetBackFacingModel, "Manages display of the back faces When <aModel> is TOBM_AUTOMATIC the object backfaces are displayed only for surface objects and never displayed for solid objects. this was the previous mode. <aModel> is TOBM_ALWAYS_DISPLAYED the object backfaces are always displayed both for surfaces or solids. <aModel> is TOBM_NEVER_DISPLAYED the object backfaces are never displayed.", py::arg("theModel"));
cls_V3d_View.def("BackFacingModel", (V3d_TypeOfBackfacingModel (V3d_View::*)() const) &V3d_View::BackFacingModel, "Returns current state of the back faces display");
cls_V3d_View.def("AddClipPlane", (void (V3d_View::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &V3d_View::AddClipPlane, "Adds clip plane to the view. The composition of clip planes truncates the rendering space to convex volume. Number of supported clip planes can be consulted by PlaneLimit method of associated Graphic3d_GraphicDriver. Please be aware that the planes which exceed the limit are ignored during rendering.", py::arg("thePlane"));
cls_V3d_View.def("RemoveClipPlane", (void (V3d_View::*)(const opencascade::handle<Graphic3d_ClipPlane> &)) &V3d_View::RemoveClipPlane, "Removes clip plane from the view.", py::arg("thePlane"));
cls_V3d_View.def("SetClipPlanes", (void (V3d_View::*)(const opencascade::handle<Graphic3d_SequenceOfHClipPlane> &)) &V3d_View::SetClipPlanes, "Sets sequence of clip planes to the view. The planes that have been set before are removed from the view. The composition of clip planes truncates the rendering space to convex volume. Number of supported clip planes can be consulted by InquirePlaneLimit method of Graphic3d_GraphicDriver. Please be aware that the planes that exceed the limit are ignored during rendering.", py::arg("thePlanes"));
cls_V3d_View.def("SetClipPlanes", (void (V3d_View::*)(const Graphic3d_SequenceOfHClipPlane &)) &V3d_View::SetClipPlanes, "None", py::arg("thePlanes"));
cls_V3d_View.def("ClipPlanes", (const opencascade::handle<Graphic3d_SequenceOfHClipPlane> & (V3d_View::*)() const) &V3d_View::ClipPlanes, "Get clip planes.");
cls_V3d_View.def("PlaneLimit", (Standard_Integer (V3d_View::*)() const) &V3d_View::PlaneLimit, "Returns the MAX number of clipping planes associated to the view.");
cls_V3d_View.def("SetCamera", (void (V3d_View::*)(const opencascade::handle<Graphic3d_Camera> &)) &V3d_View::SetCamera, "Change camera used by view.", py::arg("theCamera"));
cls_V3d_View.def("Camera", (const opencascade::handle<Graphic3d_Camera> & (V3d_View::*)() const) &V3d_View::Camera, "Returns camera object of the view.");
cls_V3d_View.def("DefaultCamera", (const opencascade::handle<Graphic3d_Camera> & (V3d_View::*)() const) &V3d_View::DefaultCamera, "Return default camera.");
cls_V3d_View.def("RenderingParams", (const Graphic3d_RenderingParams & (V3d_View::*)() const) &V3d_View::RenderingParams, "Returns current rendering parameters and effect settings. By default it returns default parameters of current viewer. To define view-specific settings use method V3d_View::ChangeRenderingParams().");
cls_V3d_View.def("ChangeRenderingParams", (Graphic3d_RenderingParams & (V3d_View::*)()) &V3d_View::ChangeRenderingParams, "Returns reference to current rendering parameters and effect settings.");
cls_V3d_View.def("IsCullingEnabled", (Standard_Boolean (V3d_View::*)() const) &V3d_View::IsCullingEnabled, "Returns flag value of objects culling mechanism");
cls_V3d_View.def("SetFrustumCulling", (void (V3d_View::*)(const Standard_Boolean)) &V3d_View::SetFrustumCulling, "Turn on/off automatic culling of objects outside frustrum (ON by default)", py::arg("theMode"));
cls_V3d_View.def("DiagnosticInformation", (void (V3d_View::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const) &V3d_View::DiagnosticInformation, "Fill in the dictionary with diagnostic info. Should be called within rendering thread.", py::arg("theDict"), py::arg("theFlags"));
cls_V3d_View.def_static("get_type_name_", (const char * (*)()) &V3d_View::get_type_name, "None");
cls_V3d_View.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_View::get_type_descriptor, "None");
cls_V3d_View.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_View::*)() const) &V3d_View::DynamicType, "None");

// Enums

}