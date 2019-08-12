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
#include <V3d_View.hxx>
#include <Standard_Handle.hxx>
#include <V3d_Viewer.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <Quantity_Color.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <V3d_TypeOfVisualization.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <V3d_TypeOfView.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
#include <V3d_ListOfView.hxx>
#include <V3d_Light.hxx>
#include <V3d_ListOfLight.hxx>
#include <gp_Ax3.hxx>
#include <Aspect_GridType.hxx>
#include <Aspect_GridDrawMode.hxx>
#include <Graphic3d_AspectMarker3d.hxx>
#include <Aspect_Grid.hxx>
#include <Graphic3d_Vertex.hxx>
#include <Quantity_TypeOfColor.hxx>
#include <Aspect_Background.hxx>
#include <TColStd_MapOfInteger.hxx>
#include <Aspect_GenId.hxx>
#include <NCollection_List.hxx>
#include <Graphic3d_Structure.hxx>
#include <V3d_RectangularGrid.hxx>
#include <V3d_CircularGrid.hxx>
#include <Graphic3d_Group.hxx>

void bind_V3d_Viewer(py::module &mod){

py::class_<V3d_Viewer, opencascade::handle<V3d_Viewer>, Standard_Transient> cls_V3d_Viewer(mod, "V3d_Viewer", "Defines services on Viewer type objects. The methods of this class allow editing and interrogation of the parameters linked to the viewer its friend classes (View,light,plane).");

// Constructors
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &>(), py::arg("theDriver"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString>(), py::arg("theDriver"), py::arg("theName"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString, const Standard_Real>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"), py::arg("theViewSize"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString, const Standard_Real, const V3d_TypeOfOrientation>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"), py::arg("theViewSize"), py::arg("theViewProj"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"), py::arg("theViewSize"), py::arg("theViewProj"), py::arg("theViewBackground"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const V3d_TypeOfVisualization>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"), py::arg("theViewSize"), py::arg("theViewProj"), py::arg("theViewBackground"), py::arg("theVisualization"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const V3d_TypeOfVisualization, const Graphic3d_TypeOfShadingModel>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"), py::arg("theViewSize"), py::arg("theViewProj"), py::arg("theViewBackground"), py::arg("theVisualization"), py::arg("theShadingModel"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const V3d_TypeOfVisualization, const Graphic3d_TypeOfShadingModel, const Standard_Boolean>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"), py::arg("theViewSize"), py::arg("theViewProj"), py::arg("theViewBackground"), py::arg("theVisualization"), py::arg("theShadingModel"), py::arg("theComputedMode"));
cls_V3d_Viewer.def(py::init<const opencascade::handle<Graphic3d_GraphicDriver> &, const Standard_ExtString, const Standard_CString, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const V3d_TypeOfVisualization, const Graphic3d_TypeOfShadingModel, const Standard_Boolean, const Standard_Boolean>(), py::arg("theDriver"), py::arg("theName"), py::arg("theDomain"), py::arg("theViewSize"), py::arg("theViewProj"), py::arg("theViewBackground"), py::arg("theVisualization"), py::arg("theShadingModel"), py::arg("theComputedMode"), py::arg("theDefaultComputedMode"));

// Fields

// Methods
cls_V3d_Viewer.def_static("get_type_name_", (const char * (*)()) &V3d_Viewer::get_type_name, "None");
cls_V3d_Viewer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_Viewer::get_type_descriptor, "None");
cls_V3d_Viewer.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_Viewer::*)() const) &V3d_Viewer::DynamicType, "None");
cls_V3d_Viewer.def("IfMoreViews", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::IfMoreViews, "Returns True if One View more can be defined in this Viewer.");
cls_V3d_Viewer.def("CreateView", (opencascade::handle<V3d_View> (V3d_Viewer::*)()) &V3d_Viewer::CreateView, "Creates a view in the viewer according to its default parameters.");
cls_V3d_Viewer.def("SetViewOn", (void (V3d_Viewer::*)()) &V3d_Viewer::SetViewOn, "Activates all of the views of a viewer attached to a window.");
cls_V3d_Viewer.def("SetViewOn", (void (V3d_Viewer::*)(const opencascade::handle<V3d_View> &)) &V3d_Viewer::SetViewOn, "Activates a particular view in the Viewer. Must be call if the Window attached to the view has been Deiconified.", py::arg("theView"));
cls_V3d_Viewer.def("SetViewOff", (void (V3d_Viewer::*)()) &V3d_Viewer::SetViewOff, "Deactivates all the views of a Viewer attached to a window.");
cls_V3d_Viewer.def("SetViewOff", (void (V3d_Viewer::*)(const opencascade::handle<V3d_View> &)) &V3d_Viewer::SetViewOff, "Deactivates a particular view in the Viewer. Must be call if the Window attached to the view has been Iconified .", py::arg("theView"));
cls_V3d_Viewer.def("Update", (void (V3d_Viewer::*)()) &V3d_Viewer::Update, "Deprecated, Redraw() should be used instead.");
cls_V3d_Viewer.def("Redraw", (void (V3d_Viewer::*)() const) &V3d_Viewer::Redraw, "Redraws all the views of the Viewer even if no modification has taken place. Must be called if all the views of the Viewer are exposed, as for example in a global DeIconification.");
cls_V3d_Viewer.def("RedrawImmediate", (void (V3d_Viewer::*)() const) &V3d_Viewer::RedrawImmediate, "Updates layer of immediate presentations.");
cls_V3d_Viewer.def("Invalidate", (void (V3d_Viewer::*)() const) &V3d_Viewer::Invalidate, "Invalidates viewer content but does not redraw it.");
cls_V3d_Viewer.def("Remove", (void (V3d_Viewer::*)()) &V3d_Viewer::Remove, "Suppresses the Viewer.");
cls_V3d_Viewer.def("Driver", (const opencascade::handle<Graphic3d_GraphicDriver> & (V3d_Viewer::*)() const) &V3d_Viewer::Driver, "Return Graphic Driver instance.");
cls_V3d_Viewer.def("StructureManager", (opencascade::handle<Graphic3d_StructureManager> (V3d_Viewer::*)() const) &V3d_Viewer::StructureManager, "Returns the structure manager associated to this viewer.");
cls_V3d_Viewer.def("DefaultRenderingParams", (const Graphic3d_RenderingParams & (V3d_Viewer::*)() const) &V3d_Viewer::DefaultRenderingParams, "Return default Rendering Parameters. By default these parameters are set in a new V3d_View.");
cls_V3d_Viewer.def("SetDefaultRenderingParams", (void (V3d_Viewer::*)(const Graphic3d_RenderingParams &)) &V3d_Viewer::SetDefaultRenderingParams, "Set default Rendering Parameters.", py::arg("theParams"));
cls_V3d_Viewer.def("SetDefaultBackgroundColor", (void (V3d_Viewer::*)(const Quantity_Color &)) &V3d_Viewer::SetDefaultBackgroundColor, "Defines the default background colour of views attached to the viewer by supplying the color object", py::arg("theColor"));
cls_V3d_Viewer.def("GetGradientBackground", (const Aspect_GradientBackground & (V3d_Viewer::*)() const) &V3d_Viewer::GetGradientBackground, "Returns the gradient background of the view.");
cls_V3d_Viewer.def("SetDefaultBgGradientColors", [](V3d_Viewer &self, const Quantity_Color & a0, const Quantity_Color & a1) -> void { return self.SetDefaultBgGradientColors(a0, a1); });
cls_V3d_Viewer.def("SetDefaultBgGradientColors", (void (V3d_Viewer::*)(const Quantity_Color &, const Quantity_Color &, const Aspect_GradientFillMethod)) &V3d_Viewer::SetDefaultBgGradientColors, "Defines the default gradient background colours of views attached to the viewer by supplying the colour objects", py::arg("theColor1"), py::arg("theColor2"), py::arg("theFillStyle"));
cls_V3d_Viewer.def("DefaultViewSize", (Standard_Real (V3d_Viewer::*)() const) &V3d_Viewer::DefaultViewSize, "Returns the default size of the view.");
cls_V3d_Viewer.def("SetDefaultViewSize", (void (V3d_Viewer::*)(const Standard_Real)) &V3d_Viewer::SetDefaultViewSize, "Gives a default size for the creation of views of the viewer.", py::arg("theSize"));
cls_V3d_Viewer.def("DefaultViewProj", (V3d_TypeOfOrientation (V3d_Viewer::*)() const) &V3d_Viewer::DefaultViewProj, "Returns the default Projection.");
cls_V3d_Viewer.def("SetDefaultViewProj", (void (V3d_Viewer::*)(const V3d_TypeOfOrientation)) &V3d_Viewer::SetDefaultViewProj, "Sets the default projection for creating views in the viewer.", py::arg("theOrientation"));
cls_V3d_Viewer.def("DefaultVisualization", (V3d_TypeOfVisualization (V3d_Viewer::*)() const) &V3d_Viewer::DefaultVisualization, "Returns the default type of Visualization.");
cls_V3d_Viewer.def("SetDefaultVisualization", (void (V3d_Viewer::*)(const V3d_TypeOfVisualization)) &V3d_Viewer::SetDefaultVisualization, "Gives the default visualization mode.", py::arg("theType"));
cls_V3d_Viewer.def("DefaultShadingModel", (Graphic3d_TypeOfShadingModel (V3d_Viewer::*)() const) &V3d_Viewer::DefaultShadingModel, "Returns the default type of Shading");
cls_V3d_Viewer.def("SetDefaultShadingModel", (void (V3d_Viewer::*)(const Graphic3d_TypeOfShadingModel)) &V3d_Viewer::SetDefaultShadingModel, "Gives the default type of SHADING.", py::arg("theType"));
cls_V3d_Viewer.def("DefaultTypeOfView", (V3d_TypeOfView (V3d_Viewer::*)() const) &V3d_Viewer::DefaultTypeOfView, "Returns the default type of View (orthographic or perspective projection) to be returned by CreateView() method.");
cls_V3d_Viewer.def("SetDefaultTypeOfView", (void (V3d_Viewer::*)(const V3d_TypeOfView)) &V3d_Viewer::SetDefaultTypeOfView, "Set the default type of View (orthographic or perspective projection) to be returned by CreateView() method.", py::arg("theType"));
cls_V3d_Viewer.def("DefaultBackgroundColor", (Quantity_Color (V3d_Viewer::*)() const) &V3d_Viewer::DefaultBackgroundColor, "Returns the default background colour object.");
cls_V3d_Viewer.def("DefaultBgGradientColors", (void (V3d_Viewer::*)(Quantity_Color &, Quantity_Color &) const) &V3d_Viewer::DefaultBgGradientColors, "Returns the gradient background colour objects of the view.", py::arg("theColor1"), py::arg("theColor2"));
cls_V3d_Viewer.def("GetAllZLayers", (void (V3d_Viewer::*)(TColStd_SequenceOfInteger &) const) &V3d_Viewer::GetAllZLayers, "Return all Z layer ids in sequence ordered by overlay level from lowest layer to highest ( foreground ). The first layer ID in sequence is the default layer that can't be removed.", py::arg("theLayerSeq"));
cls_V3d_Viewer.def("AddZLayer", (Standard_Boolean (V3d_Viewer::*)(Graphic3d_ZLayerId &)) &V3d_Viewer::AddZLayer, "Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value. The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view. The method returns Standard_False if the layer can not be created. The layer mechanism allows to display structures in higher layers in overlay of structures in lower layers.", py::arg("theLayerId"));
cls_V3d_Viewer.def("RemoveZLayer", (Standard_Boolean (V3d_Viewer::*)(const Graphic3d_ZLayerId)) &V3d_Viewer::RemoveZLayer, "Remove Z layer with ID <theLayerId>. Method returns Standard_False if the layer can not be removed or doesn't exists. By default, there are always default bottom-level layer that can't be removed.", py::arg("theLayerId"));
cls_V3d_Viewer.def("ZLayerSettings", (Graphic3d_ZLayerSettings (V3d_Viewer::*)(const Graphic3d_ZLayerId)) &V3d_Viewer::ZLayerSettings, "Returns the settings of a single Z layer.", py::arg("theLayerId"));
cls_V3d_Viewer.def("SetZLayerSettings", (void (V3d_Viewer::*)(const Graphic3d_ZLayerId, const Graphic3d_ZLayerSettings &)) &V3d_Viewer::SetZLayerSettings, "Sets the settings for a single Z layer.", py::arg("theLayerId"), py::arg("theSettings"));
cls_V3d_Viewer.def("ActiveViewIterator", (V3d_ListOfViewIterator (V3d_Viewer::*)() const) &V3d_Viewer::ActiveViewIterator, "Return an iterator for active views.");
cls_V3d_Viewer.def("InitActiveViews", (void (V3d_Viewer::*)()) &V3d_Viewer::InitActiveViews, "Initializes an internal iterator on the active views.");
cls_V3d_Viewer.def("MoreActiveViews", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::MoreActiveViews, "Returns true if there are more active view(s) to return.");
cls_V3d_Viewer.def("NextActiveViews", (void (V3d_Viewer::*)()) &V3d_Viewer::NextActiveViews, "Go to the next active view (if there is not, ActiveView will raise an exception)");
cls_V3d_Viewer.def("ActiveView", (const opencascade::handle<V3d_View> & (V3d_Viewer::*)() const) &V3d_Viewer::ActiveView, "None");
cls_V3d_Viewer.def("LastActiveView", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::LastActiveView, "returns true if there is only one active view.");
cls_V3d_Viewer.def("DefinedViewIterator", (V3d_ListOfViewIterator (V3d_Viewer::*)() const) &V3d_Viewer::DefinedViewIterator, "Return an iterator for defined views.");
cls_V3d_Viewer.def("InitDefinedViews", (void (V3d_Viewer::*)()) &V3d_Viewer::InitDefinedViews, "Initializes an internal iterator on the Defined views.");
cls_V3d_Viewer.def("MoreDefinedViews", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::MoreDefinedViews, "returns true if there are more Defined view(s) to return.");
cls_V3d_Viewer.def("NextDefinedViews", (void (V3d_Viewer::*)()) &V3d_Viewer::NextDefinedViews, "Go to the next Defined view (if there is not, DefinedView will raise an exception)");
cls_V3d_Viewer.def("DefinedView", (const opencascade::handle<V3d_View> & (V3d_Viewer::*)() const) &V3d_Viewer::DefinedView, "None");
cls_V3d_Viewer.def("SetDefaultLights", (void (V3d_Viewer::*)()) &V3d_Viewer::SetDefaultLights, "Defines default lights: positional-light 0.3 0. 0. directional-light V3d_XnegYposZpos directional-light V3d_XnegYneg ambient-light");
cls_V3d_Viewer.def("SetLightOn", (void (V3d_Viewer::*)(const opencascade::handle<V3d_Light> &)) &V3d_Viewer::SetLightOn, "Activates MyLight in the viewer.", py::arg("theLight"));
cls_V3d_Viewer.def("SetLightOn", (void (V3d_Viewer::*)()) &V3d_Viewer::SetLightOn, "Activates all the lights defined in this viewer.");
cls_V3d_Viewer.def("SetLightOff", (void (V3d_Viewer::*)(const opencascade::handle<V3d_Light> &)) &V3d_Viewer::SetLightOff, "Deactivates MyLight in this viewer.", py::arg("theLight"));
cls_V3d_Viewer.def("SetLightOff", (void (V3d_Viewer::*)()) &V3d_Viewer::SetLightOff, "Deactivate all the Lights defined in this viewer.");
cls_V3d_Viewer.def("AddLight", (void (V3d_Viewer::*)(const opencascade::handle<V3d_Light> &)) &V3d_Viewer::AddLight, "Adds Light in Sequence Of Lights.", py::arg("theLight"));
cls_V3d_Viewer.def("DelLight", (void (V3d_Viewer::*)(const opencascade::handle<V3d_Light> &)) &V3d_Viewer::DelLight, "Delete Light in Sequence Of Lights.", py::arg("theLight"));
cls_V3d_Viewer.def("UpdateLights", (void (V3d_Viewer::*)()) &V3d_Viewer::UpdateLights, "Updates the lights of all the views of a viewer.");
cls_V3d_Viewer.def("IsGlobalLight", (Standard_Boolean (V3d_Viewer::*)(const opencascade::handle<V3d_Light> &) const) &V3d_Viewer::IsGlobalLight, "None", py::arg("TheLight"));
cls_V3d_Viewer.def("ActiveLightIterator", (V3d_ListOfLightIterator (V3d_Viewer::*)() const) &V3d_Viewer::ActiveLightIterator, "Return an iterator for defined lights.");
cls_V3d_Viewer.def("InitActiveLights", (void (V3d_Viewer::*)()) &V3d_Viewer::InitActiveLights, "Initializes an internal iteratator on the active Lights.");
cls_V3d_Viewer.def("MoreActiveLights", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::MoreActiveLights, "returns true if there are more active Light(s) to return.");
cls_V3d_Viewer.def("NextActiveLights", (void (V3d_Viewer::*)()) &V3d_Viewer::NextActiveLights, "Go to the next active Light (if there is not, ActiveLight() will raise an exception)");
cls_V3d_Viewer.def("ActiveLight", (const opencascade::handle<V3d_Light> & (V3d_Viewer::*)() const) &V3d_Viewer::ActiveLight, "None");
cls_V3d_Viewer.def("DefinedLightIterator", (V3d_ListOfLightIterator (V3d_Viewer::*)() const) &V3d_Viewer::DefinedLightIterator, "Return an iterator for defined lights.");
cls_V3d_Viewer.def("InitDefinedLights", (void (V3d_Viewer::*)()) &V3d_Viewer::InitDefinedLights, "Initializes an internal iterattor on the Defined Lights.");
cls_V3d_Viewer.def("MoreDefinedLights", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::MoreDefinedLights, "Returns true if there are more Defined Light(s) to return.");
cls_V3d_Viewer.def("NextDefinedLights", (void (V3d_Viewer::*)()) &V3d_Viewer::NextDefinedLights, "Go to the next Defined Light (if there is not, DefinedLight() will raise an exception)");
cls_V3d_Viewer.def("DefinedLight", (const opencascade::handle<V3d_Light> & (V3d_Viewer::*)() const) &V3d_Viewer::DefinedLight, "None");
cls_V3d_Viewer.def("Erase", (void (V3d_Viewer::*)() const) &V3d_Viewer::Erase, "Erase all Objects in All the views.");
cls_V3d_Viewer.def("UnHighlight", (void (V3d_Viewer::*)() const) &V3d_Viewer::UnHighlight, "UnHighlight all Objects in All the views.");
cls_V3d_Viewer.def("ComputedMode", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::ComputedMode, "returns true if the computed mode can be used.");
cls_V3d_Viewer.def("SetComputedMode", (void (V3d_Viewer::*)(const Standard_Boolean)) &V3d_Viewer::SetComputedMode, "Set if the computed mode can be used.", py::arg("theMode"));
cls_V3d_Viewer.def("DefaultComputedMode", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::DefaultComputedMode, "returns true if by default the computed mode must be used.");
cls_V3d_Viewer.def("SetDefaultComputedMode", (void (V3d_Viewer::*)(const Standard_Boolean)) &V3d_Viewer::SetDefaultComputedMode, "Set if by default the computed mode must be used.", py::arg("theMode"));
cls_V3d_Viewer.def("PrivilegedPlane", (const gp_Ax3 & (V3d_Viewer::*)() const) &V3d_Viewer::PrivilegedPlane, "");
cls_V3d_Viewer.def("SetPrivilegedPlane", (void (V3d_Viewer::*)(const gp_Ax3 &)) &V3d_Viewer::SetPrivilegedPlane, "None", py::arg("thePlane"));
cls_V3d_Viewer.def("DisplayPrivilegedPlane", [](V3d_Viewer &self, const Standard_Boolean a0) -> void { return self.DisplayPrivilegedPlane(a0); });
cls_V3d_Viewer.def("DisplayPrivilegedPlane", (void (V3d_Viewer::*)(const Standard_Boolean, const Standard_Real)) &V3d_Viewer::DisplayPrivilegedPlane, "None", py::arg("theOnOff"), py::arg("theSize"));
cls_V3d_Viewer.def("ActivateGrid", (void (V3d_Viewer::*)(const Aspect_GridType, const Aspect_GridDrawMode)) &V3d_Viewer::ActivateGrid, "Activates the grid in all views of <me>.", py::arg("aGridType"), py::arg("aGridDrawMode"));
cls_V3d_Viewer.def("DeactivateGrid", (void (V3d_Viewer::*)()) &V3d_Viewer::DeactivateGrid, "Deactivates the grid in all views of <me>.");
cls_V3d_Viewer.def("SetGridEcho", [](V3d_Viewer &self) -> void { return self.SetGridEcho(); });
cls_V3d_Viewer.def("SetGridEcho", (void (V3d_Viewer::*)(const Standard_Boolean)) &V3d_Viewer::SetGridEcho, "Show/Don't show grid echo to the hit point. If TRUE,the grid echo will be shown at ConvertToGrid() time.", py::arg("showGrid"));
cls_V3d_Viewer.def("SetGridEcho", (void (V3d_Viewer::*)(const opencascade::handle<Graphic3d_AspectMarker3d> &)) &V3d_Viewer::SetGridEcho, "Show grid echo <aMarker> to the hit point. Warning: When the grid echo marker is not set, a default marker is build with the attributes: marker type : Aspect_TOM_STAR marker color : Quantity_NOC_GRAY90 marker size : 3.0", py::arg("aMarker"));
cls_V3d_Viewer.def("GridEcho", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::GridEcho, "Returns TRUE when grid echo must be displayed at hit point.");
cls_V3d_Viewer.def("IsActive", (Standard_Boolean (V3d_Viewer::*)() const) &V3d_Viewer::IsActive, "Returns Standard_True if a grid is activated in <me>.");
cls_V3d_Viewer.def("Grid", (opencascade::handle<Aspect_Grid> (V3d_Viewer::*)() const) &V3d_Viewer::Grid, "Returns the defined grid in <me>.");
cls_V3d_Viewer.def("GridType", (Aspect_GridType (V3d_Viewer::*)() const) &V3d_Viewer::GridType, "Returns the current grid type defined in <me>.");
cls_V3d_Viewer.def("GridDrawMode", (Aspect_GridDrawMode (V3d_Viewer::*)() const) &V3d_Viewer::GridDrawMode, "Returns the current grid draw mode defined in <me>.");
cls_V3d_Viewer.def("RectangularGridValues", [](V3d_Viewer &self, Standard_Real & XOrigin, Standard_Real & YOrigin, Standard_Real & XStep, Standard_Real & YStep, Standard_Real & RotationAngle){ self.RectangularGridValues(XOrigin, YOrigin, XStep, YStep, RotationAngle); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(XOrigin, YOrigin, XStep, YStep, RotationAngle); }, "Returns the definition of the rectangular grid.", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("XStep"), py::arg("YStep"), py::arg("RotationAngle"));
cls_V3d_Viewer.def("SetRectangularGridValues", (void (V3d_Viewer::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_Viewer::SetRectangularGridValues, "Sets the definition of the rectangular grid. <XOrigin>, <YOrigin> defines the origin of the grid. <XStep> defines the interval between 2 vertical lines. <YStep> defines the interval between 2 horizontal lines. <RotationAngle> defines the rotation angle of the grid.", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("XStep"), py::arg("YStep"), py::arg("RotationAngle"));
cls_V3d_Viewer.def("CircularGridValues", [](V3d_Viewer &self, Standard_Real & XOrigin, Standard_Real & YOrigin, Standard_Real & RadiusStep, Standard_Integer & DivisionNumber, Standard_Real & RotationAngle){ self.CircularGridValues(XOrigin, YOrigin, RadiusStep, DivisionNumber, RotationAngle); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Integer &, Standard_Real &>(XOrigin, YOrigin, RadiusStep, DivisionNumber, RotationAngle); }, "Returns the definition of the circular grid.", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("RadiusStep"), py::arg("DivisionNumber"), py::arg("RotationAngle"));
cls_V3d_Viewer.def("SetCircularGridValues", (void (V3d_Viewer::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Integer, const Standard_Real)) &V3d_Viewer::SetCircularGridValues, "Sets the definition of the circular grid. <XOrigin>, <YOrigin> defines the origin of the grid. <RadiusStep> defines the interval between 2 circles. <DivisionNumber> defines the section number of one half circle. <RotationAngle> defines the rotation angle of the grid.", py::arg("XOrigin"), py::arg("YOrigin"), py::arg("RadiusStep"), py::arg("DivisionNumber"), py::arg("RotationAngle"));
cls_V3d_Viewer.def("CircularGridGraphicValues", [](V3d_Viewer &self, Standard_Real & Radius, Standard_Real & OffSet){ self.CircularGridGraphicValues(Radius, OffSet); return std::tuple<Standard_Real &, Standard_Real &>(Radius, OffSet); }, "Returns the location and the size of the grid.", py::arg("Radius"), py::arg("OffSet"));
cls_V3d_Viewer.def("SetCircularGridGraphicValues", (void (V3d_Viewer::*)(const Standard_Real, const Standard_Real)) &V3d_Viewer::SetCircularGridGraphicValues, "Sets the location and the size of the grid. <XSize> defines the width of the grid. <YSize> defines the height of the grid. <OffSet> defines the displacement along the plane normal.", py::arg("Radius"), py::arg("OffSet"));
cls_V3d_Viewer.def("RectangularGridGraphicValues", [](V3d_Viewer &self, Standard_Real & XSize, Standard_Real & YSize, Standard_Real & OffSet){ self.RectangularGridGraphicValues(XSize, YSize, OffSet); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(XSize, YSize, OffSet); }, "Returns the location and the size of the grid.", py::arg("XSize"), py::arg("YSize"), py::arg("OffSet"));
cls_V3d_Viewer.def("SetRectangularGridGraphicValues", (void (V3d_Viewer::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_Viewer::SetRectangularGridGraphicValues, "Sets the location and the size of the grid. <XSize> defines the width of the grid. <YSize> defines the height of the grid. <OffSet> defines the displacement along the plane normal.", py::arg("XSize"), py::arg("YSize"), py::arg("OffSet"));
cls_V3d_Viewer.def("ShowGridEcho", (void (V3d_Viewer::*)(const opencascade::handle<V3d_View> &, const Graphic3d_Vertex &)) &V3d_Viewer::ShowGridEcho, "Display grid echo at requested point in the view.", py::arg("theView"), py::arg("thePoint"));
cls_V3d_Viewer.def("HideGridEcho", (void (V3d_Viewer::*)(const opencascade::handle<V3d_View> &)) &V3d_Viewer::HideGridEcho, "Temporarly hide grid echo.", py::arg("theView"));
cls_V3d_Viewer.def("SetDefaultBackgroundColor", (void (V3d_Viewer::*)(const Quantity_TypeOfColor, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_Viewer::SetDefaultBackgroundColor, "Defines the default base colour of views attached to the Viewer by supplying the type of colour definition and the three component values.", py::arg("theType"), py::arg("theV1"), py::arg("theV2"), py::arg("theV3"));
cls_V3d_Viewer.def("DefaultBackgroundColor", [](V3d_Viewer &self, const Quantity_TypeOfColor theType, Standard_Real & theV1, Standard_Real & theV2, Standard_Real & theV3){ self.DefaultBackgroundColor(theType, theV1, theV2, theV3); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theV1, theV2, theV3); }, "None", py::arg("theType"), py::arg("theV1"), py::arg("theV2"), py::arg("theV3"));

// Enums

}