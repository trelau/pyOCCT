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
#include <V3d_Viewer.hxx>
#include <V3d_View.hxx>
#include <V3d_StereoDumpOptions.hxx>
#include <V3d_TypeOfAxe.hxx>
#include <V3d_TypeOfBackfacingModel.hxx>
#include <V3d_TypeOfOrientation.hxx>
#include <V3d_TypeOfView.hxx>
#include <V3d_TypeOfVisualization.hxx>
#include <V3d_TypeOfPickLight.hxx>
#include <V3d_TypeOfRepresentation.hxx>
#include <V3d_TypeOfPickCamera.hxx>
#include <Standard_TypeDef.hxx>
#include <Graphic3d_BufferType.hxx>
#include <V3d_ImageDumpOptions.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Std.hxx>
#include <V3d_Trihedron.hxx>
#include <Standard_Handle.hxx>
#include <Standard_Type.hxx>
#include <Aspect_TypeOfTriedronPosition.hxx>
#include <Quantity_Color.hxx>
#include <Prs3d_ShadingAspect.hxx>
#include <Prs3d_LineAspect.hxx>
#include <Prs3d_TextAspect.hxx>
#include <Graphic3d_Structure.hxx>
#include <Graphic3d_TransformPers.hxx>
#include <Graphic3d_TypeOfLightSource.hxx>
#include <V3d_TypeOfLight.hxx>
#include <Graphic3d_CLight.hxx>
#include <V3d_Light.hxx>
#include <NCollection_List.hxx>
#include <V3d_ListOfLight.hxx>
#include <V3d_ListOfView.hxx>
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_StructureManager.hxx>
#include <Graphic3d_RenderingParams.hxx>
#include <Aspect_GradientBackground.hxx>
#include <Aspect_GradientFillMethod.hxx>
#include <Graphic3d_TypeOfShadingModel.hxx>
#include <TColStd_SequenceOfInteger.hxx>
#include <Graphic3d_ZLayerId.hxx>
#include <Graphic3d_ZLayerSettings.hxx>
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
#include <V3d_RectangularGrid.hxx>
#include <V3d_CircularGrid.hxx>
#include <Graphic3d_Group.hxx>
#include <V3d_ViewerPointer.hxx>
#include <Aspect_Window.hxx>
#include <Aspect_RenderingContext.hxx>
#include <Aspect_FillMethod.hxx>
#include <Graphic3d_CubeMap.hxx>
#include <Graphic3d_TextureEnv.hxx>
#include <Graphic3d_GraduatedTrihedron.hxx>
#include <Bnd_Box.hxx>
#include <Graphic3d_CView.hxx>
#include <Graphic3d_Camera.hxx>
#include <Image_PixMap.hxx>
#include <Graphic3d_ClipPlane.hxx>
#include <Graphic3d_SequenceOfHClipPlane.hxx>
#include <TColStd_IndexedDataMapOfStringString.hxx>
#include <Graphic3d_DiagnosticInfo.hxx>
#include <TCollection_AsciiString.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <gp_Vec.hxx>
#include <gp_XYZ.hxx>
#include <TColStd_Array2OfReal.hxx>
#include <Standard.hxx>
#include <gp.hxx>
#include <V3d.hxx>
#include <V3d_AmbientLight.hxx>
#include <Standard_OutOfRange.hxx>
#include <V3d_BadValue.hxx>
#include <Standard_SStream.hxx>
#include <Aspect_CircularGrid.hxx>
#include <V3d_Coordinate.hxx>
#include <V3d_PositionLight.hxx>
#include <V3d_DirectionalLight.hxx>
#include <V3d_Parameter.hxx>
#include <V3d_Plane.hxx>
#include <V3d_PositionalLight.hxx>
#include <Aspect_RectangularGrid.hxx>
#include <V3d_SpotLight.hxx>
#include <V3d_TypeOfShadingModel.hxx>
#include <Standard_DomainError.hxx>
#include <V3d_UnMapped.hxx>
#include <V3d_ViewPointer.hxx>
#include <bind_NCollection_List.hxx>
#include <bind_NCollection_TListIterator.hxx>

PYBIND11_MODULE(V3d, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Graphic3d");
py::module::import("OCCT.Aspect");
py::module::import("OCCT.Quantity");
py::module::import("OCCT.Prs3d");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.gp");
py::module::import("OCCT.Bnd");
py::module::import("OCCT.Image");
py::module::import("OCCT.TCollection");

// ENUM: V3D_STEREODUMPOPTIONS
py::enum_<V3d_StereoDumpOptions>(mod, "V3d_StereoDumpOptions", "Options to be used with image dumping. Notice that the value will have no effect with disabled stereo output.")
	.value("V3d_SDO_MONO", V3d_StereoDumpOptions::V3d_SDO_MONO)
	.value("V3d_SDO_LEFT_EYE", V3d_StereoDumpOptions::V3d_SDO_LEFT_EYE)
	.value("V3d_SDO_RIGHT_EYE", V3d_StereoDumpOptions::V3d_SDO_RIGHT_EYE)
	.value("V3d_SDO_BLENDED", V3d_StereoDumpOptions::V3d_SDO_BLENDED)
	.export_values();


// ENUM: V3D_TYPEOFAXE
py::enum_<V3d_TypeOfAxe>(mod, "V3d_TypeOfAxe", "Determines the axis type through the coordinates X, Y, Z.")
	.value("V3d_X", V3d_TypeOfAxe::V3d_X)
	.value("V3d_Y", V3d_TypeOfAxe::V3d_Y)
	.value("V3d_Z", V3d_TypeOfAxe::V3d_Z)
	.export_values();


// ENUM: V3D_TYPEOFBACKFACINGMODEL
py::enum_<V3d_TypeOfBackfacingModel>(mod, "V3d_TypeOfBackfacingModel", "Modes of display of back faces in the view")
	.value("V3d_TOBM_AUTOMATIC", V3d_TypeOfBackfacingModel::V3d_TOBM_AUTOMATIC)
	.value("V3d_TOBM_ALWAYS_DISPLAYED", V3d_TypeOfBackfacingModel::V3d_TOBM_ALWAYS_DISPLAYED)
	.value("V3d_TOBM_NEVER_DISPLAYED", V3d_TypeOfBackfacingModel::V3d_TOBM_NEVER_DISPLAYED)
	.export_values();


// ENUM: V3D_TYPEOFORIENTATION
py::enum_<V3d_TypeOfOrientation>(mod, "V3d_TypeOfOrientation", "Determines the type of orientation as a combination of standard DX/DY/DZ directions. This enumeration defines a model orientation looking towards the user's eye, which is an opposition to Camera main direction. For example, V3d_Xneg defines +X Camera main direction.")
	.value("V3d_Xpos", V3d_TypeOfOrientation::V3d_Xpos)
	.value("V3d_Ypos", V3d_TypeOfOrientation::V3d_Ypos)
	.value("V3d_Zpos", V3d_TypeOfOrientation::V3d_Zpos)
	.value("V3d_Xneg", V3d_TypeOfOrientation::V3d_Xneg)
	.value("V3d_Yneg", V3d_TypeOfOrientation::V3d_Yneg)
	.value("V3d_Zneg", V3d_TypeOfOrientation::V3d_Zneg)
	.value("V3d_XposYpos", V3d_TypeOfOrientation::V3d_XposYpos)
	.value("V3d_XposZpos", V3d_TypeOfOrientation::V3d_XposZpos)
	.value("V3d_YposZpos", V3d_TypeOfOrientation::V3d_YposZpos)
	.value("V3d_XnegYneg", V3d_TypeOfOrientation::V3d_XnegYneg)
	.value("V3d_XnegYpos", V3d_TypeOfOrientation::V3d_XnegYpos)
	.value("V3d_XnegZneg", V3d_TypeOfOrientation::V3d_XnegZneg)
	.value("V3d_XnegZpos", V3d_TypeOfOrientation::V3d_XnegZpos)
	.value("V3d_YnegZneg", V3d_TypeOfOrientation::V3d_YnegZneg)
	.value("V3d_YnegZpos", V3d_TypeOfOrientation::V3d_YnegZpos)
	.value("V3d_XposYneg", V3d_TypeOfOrientation::V3d_XposYneg)
	.value("V3d_XposZneg", V3d_TypeOfOrientation::V3d_XposZneg)
	.value("V3d_YposZneg", V3d_TypeOfOrientation::V3d_YposZneg)
	.value("V3d_XposYposZpos", V3d_TypeOfOrientation::V3d_XposYposZpos)
	.value("V3d_XposYnegZpos", V3d_TypeOfOrientation::V3d_XposYnegZpos)
	.value("V3d_XposYposZneg", V3d_TypeOfOrientation::V3d_XposYposZneg)
	.value("V3d_XnegYposZpos", V3d_TypeOfOrientation::V3d_XnegYposZpos)
	.value("V3d_XposYnegZneg", V3d_TypeOfOrientation::V3d_XposYnegZneg)
	.value("V3d_XnegYposZneg", V3d_TypeOfOrientation::V3d_XnegYposZneg)
	.value("V3d_XnegYnegZpos", V3d_TypeOfOrientation::V3d_XnegYnegZpos)
	.value("V3d_XnegYnegZneg", V3d_TypeOfOrientation::V3d_XnegYnegZneg)
	.value("V3d_TypeOfOrientation_Zup_AxoLeft", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_AxoLeft)
	.value("V3d_TypeOfOrientation_Zup_AxoRight", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_AxoRight)
	.value("V3d_TypeOfOrientation_Zup_Front", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_Front)
	.value("V3d_TypeOfOrientation_Zup_Back", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_Back)
	.value("V3d_TypeOfOrientation_Zup_Top", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_Top)
	.value("V3d_TypeOfOrientation_Zup_Bottom", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_Bottom)
	.value("V3d_TypeOfOrientation_Zup_Left", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_Left)
	.value("V3d_TypeOfOrientation_Zup_Right", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Zup_Right)
	.value("V3d_TypeOfOrientation_Yup_AxoLeft", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_AxoLeft)
	.value("V3d_TypeOfOrientation_Yup_AxoRight", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_AxoRight)
	.value("V3d_TypeOfOrientation_Yup_Front", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_Front)
	.value("V3d_TypeOfOrientation_Yup_Back", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_Back)
	.value("V3d_TypeOfOrientation_Yup_Top", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_Top)
	.value("V3d_TypeOfOrientation_Yup_Bottom", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_Bottom)
	.value("V3d_TypeOfOrientation_Yup_Left", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_Left)
	.value("V3d_TypeOfOrientation_Yup_Right", V3d_TypeOfOrientation::V3d_TypeOfOrientation_Yup_Right)
	.export_values();


// ENUM: V3D_TYPEOFVIEW
py::enum_<V3d_TypeOfView>(mod, "V3d_TypeOfView", "Defines the type of projection of the view.")
	.value("V3d_ORTHOGRAPHIC", V3d_TypeOfView::V3d_ORTHOGRAPHIC)
	.value("V3d_PERSPECTIVE", V3d_TypeOfView::V3d_PERSPECTIVE)
	.export_values();


// ENUM: V3D_TYPEOFVISUALIZATION
py::enum_<V3d_TypeOfVisualization>(mod, "V3d_TypeOfVisualization", "Determines the type of visualization in the view, either WIREFRAME or ZBUFFER (shading).")
	.value("V3d_WIREFRAME", V3d_TypeOfVisualization::V3d_WIREFRAME)
	.value("V3d_ZBUFFER", V3d_TypeOfVisualization::V3d_ZBUFFER)
	.export_values();


// ENUM: V3D_TYPEOFPICKLIGHT
py::enum_<V3d_TypeOfPickLight>(mod, "V3d_TypeOfPickLight", "None")
	.value("V3d_POSITIONLIGHT", V3d_TypeOfPickLight::V3d_POSITIONLIGHT)
	.value("V3d_SPACELIGHT", V3d_TypeOfPickLight::V3d_SPACELIGHT)
	.value("V3d_RADIUSTEXTLIGHT", V3d_TypeOfPickLight::V3d_RADIUSTEXTLIGHT)
	.value("V3d_ExtRADIUSLIGHT", V3d_TypeOfPickLight::V3d_ExtRADIUSLIGHT)
	.value("V3d_IntRADIUSLIGHT", V3d_TypeOfPickLight::V3d_IntRADIUSLIGHT)
	.value("V3d_NOTHING", V3d_TypeOfPickLight::V3d_NOTHING)
	.export_values();


// ENUM: V3D_TYPEOFREPRESENTATION
py::enum_<V3d_TypeOfRepresentation>(mod, "V3d_TypeOfRepresentation", "None")
	.value("V3d_SIMPLE", V3d_TypeOfRepresentation::V3d_SIMPLE)
	.value("V3d_COMPLETE", V3d_TypeOfRepresentation::V3d_COMPLETE)
	.value("V3d_PARTIAL", V3d_TypeOfRepresentation::V3d_PARTIAL)
	.value("V3d_SAMELAST", V3d_TypeOfRepresentation::V3d_SAMELAST)
	.export_values();


// ENUM: V3D_TYPEOFPICKCAMERA
py::enum_<V3d_TypeOfPickCamera>(mod, "V3d_TypeOfPickCamera", "None")
	.value("V3d_POSITIONCAMERA", V3d_TypeOfPickCamera::V3d_POSITIONCAMERA)
	.value("V3d_SPACECAMERA", V3d_TypeOfPickCamera::V3d_SPACECAMERA)
	.value("V3d_RADIUSTEXTCAMERA", V3d_TypeOfPickCamera::V3d_RADIUSTEXTCAMERA)
	.value("V3d_ExtRADIUSCAMERA", V3d_TypeOfPickCamera::V3d_ExtRADIUSCAMERA)
	.value("V3d_IntRADIUSCAMERA", V3d_TypeOfPickCamera::V3d_IntRADIUSCAMERA)
	.value("V3d_NOTHINGCAMERA", V3d_TypeOfPickCamera::V3d_NOTHINGCAMERA)
	.export_values();


// CLASS: V3D_IMAGEDUMPOPTIONS
py::class_<V3d_ImageDumpOptions> cls_V3d_ImageDumpOptions(mod, "V3d_ImageDumpOptions", "The structure defines options for image dump functionality.");

// Constructors
cls_V3d_ImageDumpOptions.def(py::init<>());

// Fields
cls_V3d_ImageDumpOptions.def_readwrite("Width", &V3d_ImageDumpOptions::Width, "width of image dump to allocate an image, 0 by default (meaning that image should be already allocated)");
cls_V3d_ImageDumpOptions.def_readwrite("Height", &V3d_ImageDumpOptions::Height, "height of image dump to allocate an image, 0 by default (meaning that image should be already allocated)");
cls_V3d_ImageDumpOptions.def_readwrite("BufferType", &V3d_ImageDumpOptions::BufferType, "which buffer to dump (color / depth), Graphic3d_BT_RGB by default");
cls_V3d_ImageDumpOptions.def_readwrite("StereoOptions", &V3d_ImageDumpOptions::StereoOptions, "dumping stereoscopic camera, V3d_SDO_MONO by default (middle-point monographic projection)");
cls_V3d_ImageDumpOptions.def_readwrite("TileSize", &V3d_ImageDumpOptions::TileSize, "the view dimension limited for tiled dump, 0 by default (automatic tiling depending on hardware capabilities)");
cls_V3d_ImageDumpOptions.def_readwrite("ToAdjustAspect", &V3d_ImageDumpOptions::ToAdjustAspect, "flag to override active view aspect ratio by (Width / Height) defined for image dump (TRUE by default)");

// CLASS: V3D_TRIHEDRON
py::class_<V3d_Trihedron, opencascade::handle<V3d_Trihedron>, Standard_Transient> cls_V3d_Trihedron(mod, "V3d_Trihedron", "Class for presentation of zbuffer trihedron object.");

// Constructors
cls_V3d_Trihedron.def(py::init<>());

// Methods
cls_V3d_Trihedron.def_static("get_type_name_", (const char * (*)()) &V3d_Trihedron::get_type_name, "None");
cls_V3d_Trihedron.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_Trihedron::get_type_descriptor, "None");
cls_V3d_Trihedron.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_Trihedron::*)() const) &V3d_Trihedron::DynamicType, "None");
cls_V3d_Trihedron.def("SetWireframe", (void (V3d_Trihedron::*)(const Standard_Boolean)) &V3d_Trihedron::SetWireframe, "Switch wireframe / shaded trihedron.", py::arg("theAsWireframe"));
cls_V3d_Trihedron.def("SetPosition", (void (V3d_Trihedron::*)(const Aspect_TypeOfTriedronPosition)) &V3d_Trihedron::SetPosition, "Setup the corner to draw the trihedron.", py::arg("thePosition"));
cls_V3d_Trihedron.def("SetScale", (void (V3d_Trihedron::*)(const Standard_Real)) &V3d_Trihedron::SetScale, "Setup the scale factor.", py::arg("theScale"));
cls_V3d_Trihedron.def("SetSizeRatio", (void (V3d_Trihedron::*)(const Standard_Real)) &V3d_Trihedron::SetSizeRatio, "Setup the size ratio factor.", py::arg("theRatio"));
cls_V3d_Trihedron.def("SetArrowDiameter", (void (V3d_Trihedron::*)(const Standard_Real)) &V3d_Trihedron::SetArrowDiameter, "Setup the arrow diameter.", py::arg("theDiam"));
cls_V3d_Trihedron.def("SetNbFacets", (void (V3d_Trihedron::*)(const Standard_Integer)) &V3d_Trihedron::SetNbFacets, "Setup the number of facets for tessellation.", py::arg("theNbFacets"));
cls_V3d_Trihedron.def("SetLabelsColor", (void (V3d_Trihedron::*)(const Quantity_Color &)) &V3d_Trihedron::SetLabelsColor, "Setup color of text labels.", py::arg("theColor"));
cls_V3d_Trihedron.def("SetArrowsColor", (void (V3d_Trihedron::*)(const Quantity_Color &, const Quantity_Color &, const Quantity_Color &)) &V3d_Trihedron::SetArrowsColor, "Setup colors of arrows.", py::arg("theXColor"), py::arg("theYColor"), py::arg("theZColor"));
cls_V3d_Trihedron.def("Display", (void (V3d_Trihedron::*)(const V3d_View &)) &V3d_Trihedron::Display, "Display trihedron.", py::arg("theView"));
cls_V3d_Trihedron.def("Erase", (void (V3d_Trihedron::*)()) &V3d_Trihedron::Erase, "Erase trihedron.");

// TYPEDEF: V3D_TYPEOFLIGHT

// TYPEDEF: V3D_LIGHT
py::class_<Graphic3d_CLight, opencascade::handle<Graphic3d_CLight>, Standard_Transient> cls_V3d_Light(mod, "V3d_Light", "Generic light source definition. This class defines arbitrary light source - see Graphic3d_TypeOfLightSource enumeration. Some parameters are applicable only to particular light type; calling methods unrelated to current type will throw an exception.", py::module_local());

// Constructors
cls_V3d_Light.def(py::init<Graphic3d_TypeOfLightSource>(), py::arg("theType"));

// Methods
cls_V3d_Light.def_static("get_type_name_", (const char * (*)()) &Graphic3d_CLight::get_type_name, "None");
cls_V3d_Light.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_CLight::get_type_descriptor, "None");
cls_V3d_Light.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::DynamicType, "None");
cls_V3d_Light.def("Type", (Graphic3d_TypeOfLightSource (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Type, "Returns the Type of the Light, cannot be changed after object construction.");
cls_V3d_Light.def("Name", (const TCollection_AsciiString & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Name, "Returns light source name; empty string by default.");
cls_V3d_Light.def("SetName", (void (Graphic3d_CLight::*)(const TCollection_AsciiString &)) &Graphic3d_CLight::SetName, "Sets light source name.", py::arg("theName"));
cls_V3d_Light.def("Color", (const Quantity_Color & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Color, "Returns the color of the light source; WHITE by default.");
cls_V3d_Light.def("SetColor", (void (Graphic3d_CLight::*)(const Quantity_Color &)) &Graphic3d_CLight::SetColor, "Defines the color of a light source by giving the basic color.", py::arg("theColor"));
cls_V3d_Light.def("IsEnabled", (Standard_Boolean (Graphic3d_CLight::*)() const) &Graphic3d_CLight::IsEnabled, "Check that the light source is turned on; TRUE by default. This flag affects all occurrences of light sources, where it was registered and activated; so that it is possible defining an active light in View which is actually in disabled state.");
cls_V3d_Light.def("SetEnabled", (void (Graphic3d_CLight::*)(Standard_Boolean)) &Graphic3d_CLight::SetEnabled, "Change enabled state of the light state. This call does not remove or deactivate light source in Views/Viewers; instead it turns it OFF so that it just have no effect.", py::arg("theIsOn"));
cls_V3d_Light.def("IsHeadlight", (Standard_Boolean (Graphic3d_CLight::*)() const) &Graphic3d_CLight::IsHeadlight, "Returns true if the light is a headlight; FALSE by default. Headlight flag means that light position/direction are defined not in a World coordinate system, but relative to the camera orientation.");
cls_V3d_Light.def("Headlight", (Standard_Boolean (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Headlight, "Alias for IsHeadlight().");
cls_V3d_Light.def("SetHeadlight", (void (Graphic3d_CLight::*)(Standard_Boolean)) &Graphic3d_CLight::SetHeadlight, "Setup headlight flag.", py::arg("theValue"));
cls_V3d_Light.def("Position", (const gp_Pnt & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Position, "Returns location of positional/spot light; (0, 0, 0) by default.");
cls_V3d_Light.def("SetPosition", (void (Graphic3d_CLight::*)(const gp_Pnt &)) &Graphic3d_CLight::SetPosition, "Setup location of positional/spot light.", py::arg("thePosition"));
cls_V3d_Light.def("Position", [](Graphic3d_CLight &self, Standard_Real & theX, Standard_Real & theY, Standard_Real & theZ){ self.Position(theX, theY, theZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theX, theY, theZ); }, "Returns location of positional/spot light.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_V3d_Light.def("SetPosition", (void (Graphic3d_CLight::*)(Standard_Real, Standard_Real, Standard_Real)) &Graphic3d_CLight::SetPosition, "Setup location of positional/spot light.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_V3d_Light.def("ConstAttenuation", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::ConstAttenuation, "Returns constant attenuation factor of positional/spot light source; 1.0f by default. Distance attenuation factors of reducing positional/spot light intensity depending on the distance from its position:");
cls_V3d_Light.def("LinearAttenuation", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::LinearAttenuation, "Returns linear attenuation factor of positional/spot light source; 0.0 by default. Distance attenuation factors of reducing positional/spot light intensity depending on the distance from its position:");
cls_V3d_Light.def("Attenuation", [](Graphic3d_CLight &self, Standard_Real & theConstAttenuation, Standard_Real & theLinearAttenuation){ self.Attenuation(theConstAttenuation, theLinearAttenuation); return std::tuple<Standard_Real &, Standard_Real &>(theConstAttenuation, theLinearAttenuation); }, "Returns the attenuation factors.", py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_V3d_Light.def("SetAttenuation", (void (Graphic3d_CLight::*)(Standard_ShortReal, Standard_ShortReal)) &Graphic3d_CLight::SetAttenuation, "Defines the coefficients of attenuation; values should be >= 0.0 and their summ should not be equal to 0.", py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_V3d_Light.def("Direction", (gp_Dir (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Direction, "Returns direction of directional/spot light.");
cls_V3d_Light.def("SetDirection", (void (Graphic3d_CLight::*)(const gp_Dir &)) &Graphic3d_CLight::SetDirection, "Sets direction of directional/spot light.", py::arg("theDir"));
cls_V3d_Light.def("Direction", [](Graphic3d_CLight &self, Standard_Real & theVx, Standard_Real & theVy, Standard_Real & theVz){ self.Direction(theVx, theVy, theVz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theVx, theVy, theVz); }, "Returns the theVx, theVy, theVz direction of the light source.", py::arg("theVx"), py::arg("theVy"), py::arg("theVz"));
cls_V3d_Light.def("SetDirection", (void (Graphic3d_CLight::*)(Standard_Real, Standard_Real, Standard_Real)) &Graphic3d_CLight::SetDirection, "Sets direction of directional/spot light.", py::arg("theVx"), py::arg("theVy"), py::arg("theVz"));
cls_V3d_Light.def("Angle", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Angle, "Returns an angle in radians of the cone created by the spot; 30 degrees by default.");
cls_V3d_Light.def("SetAngle", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetAngle, "Angle in radians of the cone created by the spot, should be within range (0.0, M_PI).", py::arg("theAngle"));
cls_V3d_Light.def("Concentration", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Concentration, "Returns intensity distribution of the spot light, within [0.0, 1.0] range; 1.0 by default. This coefficient should be converted into spotlight exponent within [0.0, 128.0] range: The concentration factor determines the dispersion of the light on the surface, the default value (1.0) corresponds to a minimum of dispersion.");
cls_V3d_Light.def("SetConcentration", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetConcentration, "Defines the coefficient of concentration; value should be within range [0.0, 1.0].", py::arg("theConcentration"));
cls_V3d_Light.def("Intensity", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Intensity, "Returns the intensity of light source; 1.0 by default.");
cls_V3d_Light.def("SetIntensity", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetIntensity, "Modifies the intensity of light source, which should be > 0.0.", py::arg("theValue"));
cls_V3d_Light.def("Smoothness", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Smoothness, "Returns the smoothness of light source (either smoothing angle for directional light or smoothing radius in case of positional light); 0.0 by default.");
cls_V3d_Light.def("SetSmoothRadius", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetSmoothRadius, "Modifies the smoothing radius of positional/spot light; should be >= 0.0.", py::arg("theValue"));
cls_V3d_Light.def("SetSmoothAngle", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetSmoothAngle, "Modifies the smoothing angle (in radians) of directional light source; should be within range [0.0, M_PI/2].", py::arg("theValue"));
cls_V3d_Light.def("GetId", (const TCollection_AsciiString & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::GetId, "Returns light resource identifier string");
cls_V3d_Light.def("PackedParams", (const Graphic3d_Vec4 & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::PackedParams, "Packed light parameters.");
cls_V3d_Light.def("PackedColor", (const Graphic3d_Vec4 & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::PackedColor, "Returns the color of the light source with dummy Alpha component, which should be ignored.");
cls_V3d_Light.def("PackedDirection", (const Graphic3d_Vec4 & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::PackedDirection, "Returns direction of directional/spot light.");
cls_V3d_Light.def("Revision", (Standard_Size (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Revision, "Returns modification counter");

// TYPEDEF: V3D_LISTOFLIGHT
bind_NCollection_List<opencascade::handle<Graphic3d_CLight> >(mod, "V3d_ListOfLight", py::module_local(false));

// TYPEDEF: V3D_LISTOFLIGHTITERATOR
bind_NCollection_TListIterator<opencascade::handle<Graphic3d_CLight> >(mod, "V3d_ListOfLightIterator", py::module_local(false));

// TYPEDEF: V3D_LISTOFVIEW
bind_NCollection_List<opencascade::handle<V3d_View> >(mod, "V3d_ListOfView", py::module_local(false));

// TYPEDEF: V3D_LISTOFVIEWITERATOR
bind_NCollection_TListIterator<opencascade::handle<V3d_View> >(mod, "V3d_ListOfViewIterator", py::module_local(false));

// CLASS: V3D_VIEWER
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
cls_V3d_Viewer.def("AddZLayer", [](V3d_Viewer &self, Graphic3d_ZLayerId & a0) -> Standard_Boolean { return self.AddZLayer(a0); });
cls_V3d_Viewer.def("AddZLayer", (Standard_Boolean (V3d_Viewer::*)(Graphic3d_ZLayerId &, const Graphic3d_ZLayerSettings &)) &V3d_Viewer::AddZLayer, "Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value. The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view. Custom layers will be inserted before Graphic3d_ZLayerId_Top (e.g. between Graphic3d_ZLayerId_Default and before Graphic3d_ZLayerId_Top).", py::arg("theLayerId"), py::arg("theSettings"));
cls_V3d_Viewer.def("InsertLayerBefore", (Standard_Boolean (V3d_Viewer::*)(Graphic3d_ZLayerId &, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &V3d_Viewer::InsertLayerBefore, "Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value. The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view. Layer rendering order is defined by its position in list (altered by theLayerAfter) and IsImmediate() flag (all layers with IsImmediate() flag are drawn afterwards);", py::arg("theNewLayerId"), py::arg("theSettings"), py::arg("theLayerAfter"));
cls_V3d_Viewer.def("InsertLayerAfter", (Standard_Boolean (V3d_Viewer::*)(Graphic3d_ZLayerId &, const Graphic3d_ZLayerSettings &, const Graphic3d_ZLayerId)) &V3d_Viewer::InsertLayerAfter, "Add a new top-level Z layer to all managed views and get its ID as <theLayerId> value. The Z layers are controlled entirely by viewer, it is not possible to add a layer to a particular view. Layer rendering order is defined by its position in list (altered by theLayerAfter) and IsImmediate() flag (all layers with IsImmediate() flag are drawn afterwards);", py::arg("theNewLayerId"), py::arg("theSettings"), py::arg("theLayerBefore"));
cls_V3d_Viewer.def("RemoveZLayer", (Standard_Boolean (V3d_Viewer::*)(const Graphic3d_ZLayerId)) &V3d_Viewer::RemoveZLayer, "Remove Z layer with ID <theLayerId>. Method returns Standard_False if the layer can not be removed or doesn't exists. By default, there are always default bottom-level layer that can't be removed.", py::arg("theLayerId"));
cls_V3d_Viewer.def("ZLayerSettings", (const Graphic3d_ZLayerSettings & (V3d_Viewer::*)(const Graphic3d_ZLayerId) const) &V3d_Viewer::ZLayerSettings, "Returns the settings of a single Z layer.", py::arg("theLayerId"));
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

// TYPEDEF: V3D_VIEWERPOINTER

// CLASS: V3D_VIEW
py::class_<V3d_View, opencascade::handle<V3d_View>, Standard_Transient> cls_V3d_View(mod, "V3d_View", "Defines the application object VIEW for the VIEWER application. The methods of this class allow the editing and inquiring the parameters linked to the view. Provides a set of services common to all types of view. Warning: The default parameters are defined by the class Viewer (Example : SetDefaultViewSize()). Certain methods are mouse oriented, and it is necessary to know the difference between the start and the continuation of this gesture in putting the method into operation. Example : Shifting the eye-view along the screen axes.");

// Constructors
cls_V3d_View.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("theViewer"));
cls_V3d_View.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfView>(), py::arg("theViewer"), py::arg("theType"));
cls_V3d_View.def(py::init<const opencascade::handle<V3d_Viewer> &, const opencascade::handle<V3d_View> &>(), py::arg("theViewer"), py::arg("theView"));

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
cls_V3d_View.def("IsInvalidatedImmediate", (Standard_Boolean (V3d_View::*)() const) &V3d_View::IsInvalidatedImmediate, "Returns true if immediate layer content has been invalidated.");
cls_V3d_View.def("InvalidateImmediate", (void (V3d_View::*)()) &V3d_View::InvalidateImmediate, "Invalidates view content within immediate layer but does not redraw it.");
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
cls_V3d_View.def("SetBackgroundCubeMap", [](V3d_View &self, const opencascade::handle<Graphic3d_CubeMap> & a0) -> void { return self.SetBackgroundCubeMap(a0); });
cls_V3d_View.def("SetBackgroundCubeMap", (void (V3d_View::*)(const opencascade::handle<Graphic3d_CubeMap> &, Standard_Boolean)) &V3d_View::SetBackgroundCubeMap, "Sets environment cubemap as interactive background.", py::arg("theCubeMap"), py::arg("theToUpdate"));
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
cls_V3d_View.def("SetProj", [](V3d_View &self, const V3d_TypeOfOrientation a0) -> void { return self.SetProj(a0); });
cls_V3d_View.def("SetProj", (void (V3d_View::*)(const V3d_TypeOfOrientation, const Standard_Boolean)) &V3d_View::SetProj, "Defines the orientation of the projection .", py::arg("theOrientation"), py::arg("theIsYup"));
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
cls_V3d_View.def("Window", (const opencascade::handle<Aspect_Window> & (V3d_View::*)() const) &V3d_View::Window, "Returns the Aspect Window associated with the view.");
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
cls_V3d_View.def("View", (const opencascade::handle<Graphic3d_CView> & (V3d_View::*)() const) &V3d_View::View, "Returns the associated Graphic3d view.");
cls_V3d_View.def("SetComputedMode", (void (V3d_View::*)(const Standard_Boolean)) &V3d_View::SetComputedMode, "Switches computed HLR mode in the view.", py::arg("theMode"));
cls_V3d_View.def("ComputedMode", (Standard_Boolean (V3d_View::*)() const) &V3d_View::ComputedMode, "Returns the computed HLR mode state.");
cls_V3d_View.def("WindowFitAll", (void (V3d_View::*)(const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer)) &V3d_View::WindowFitAll, "idem than WindowFit", py::arg("Xmin"), py::arg("Ymin"), py::arg("Xmax"), py::arg("Ymax"));
cls_V3d_View.def("FitMinMax", [](V3d_View &self, const opencascade::handle<Graphic3d_Camera> & a0, const Bnd_Box & a1, const Standard_Real a2) -> Standard_Boolean { return self.FitMinMax(a0, a1, a2); });
cls_V3d_View.def("FitMinMax", [](V3d_View &self, const opencascade::handle<Graphic3d_Camera> & a0, const Bnd_Box & a1, const Standard_Real a2, const Standard_Real a3) -> Standard_Boolean { return self.FitMinMax(a0, a1, a2, a3); });
cls_V3d_View.def("FitMinMax", (Standard_Boolean (V3d_View::*)(const opencascade::handle<Graphic3d_Camera> &, const Bnd_Box &, const Standard_Real, const Standard_Real, const Standard_Boolean) const) &V3d_View::FitMinMax, "Transform camera eye, center and scale to fit in the passed bounding box specified in WCS.", py::arg("theCamera"), py::arg("theBox"), py::arg("theMargin"), py::arg("theResolution"), py::arg("theToEnlargeIfLine"));
cls_V3d_View.def("SetGrid", (void (V3d_View::*)(const gp_Ax3 &, const opencascade::handle<Aspect_Grid> &)) &V3d_View::SetGrid, "Defines or Updates the definition of the grid in <me>", py::arg("aPlane"), py::arg("aGrid"));
cls_V3d_View.def("SetGridActivity", (void (V3d_View::*)(const Standard_Boolean)) &V3d_View::SetGridActivity, "Defines or Updates the activity of the grid in <me>", py::arg("aFlag"));
cls_V3d_View.def("Dump", [](V3d_View &self, const Standard_CString a0) -> Standard_Boolean { return self.Dump(a0); });
cls_V3d_View.def("Dump", (Standard_Boolean (V3d_View::*)(const Standard_CString, const Graphic3d_BufferType &)) &V3d_View::Dump, "Dumps the full contents of the View into the image file. This is an alias for ToPixMap() with Image_AlienPixMap.", py::arg("theFile"), py::arg("theBufferType"));
cls_V3d_View.def("ToPixMap", (Standard_Boolean (V3d_View::*)(Image_PixMap &, const V3d_ImageDumpOptions &)) &V3d_View::ToPixMap, "Dumps the full contents of the view to a pixmap with specified parameters. Internally this method calls Redraw() with an offscreen render buffer of requested target size (theWidth x theHeight), so that there is no need resizing a window control for making a dump of different size.", py::arg("theImage"), py::arg("theParams"));
cls_V3d_View.def("ToPixMap", [](V3d_View &self, Image_PixMap & a0, const Standard_Integer a1, const Standard_Integer a2) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2); });
cls_V3d_View.def("ToPixMap", [](V3d_View &self, Image_PixMap & a0, const Standard_Integer a1, const Standard_Integer a2, const Graphic3d_BufferType & a3) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2, a3); });
cls_V3d_View.def("ToPixMap", [](V3d_View &self, Image_PixMap & a0, const Standard_Integer a1, const Standard_Integer a2, const Graphic3d_BufferType & a3, const Standard_Boolean a4) -> Standard_Boolean { return self.ToPixMap(a0, a1, a2, a3, a4); });
cls_V3d_View.def("ToPixMap", (Standard_Boolean (V3d_View::*)(Image_PixMap &, const Standard_Integer, const Standard_Integer, const Graphic3d_BufferType &, const Standard_Boolean, const V3d_StereoDumpOptions)) &V3d_View::ToPixMap, "Dumps the full contents of the view to a pixmap. Internally this method calls Redraw() with an offscreen render buffer of requested target size (theWidth x theHeight), so that there is no need resizing a window control for making a dump of different size.", py::arg("theImage"), py::arg("theWidth"), py::arg("theHeight"), py::arg("theBufferType"), py::arg("theToAdjustAspect"), py::arg("theStereoOptions"));
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
cls_V3d_View.def("SetFrustumCulling", (void (V3d_View::*)(Standard_Boolean)) &V3d_View::SetFrustumCulling, "Turn on/off automatic culling of objects outside frustum (ON by default)", py::arg("theMode"));
cls_V3d_View.def("DiagnosticInformation", (void (V3d_View::*)(TColStd_IndexedDataMapOfStringString &, Graphic3d_DiagnosticInfo) const) &V3d_View::DiagnosticInformation, "Fill in the dictionary with diagnostic info. Should be called within rendering thread.", py::arg("theDict"), py::arg("theFlags"));
cls_V3d_View.def("StatisticInformation", (TCollection_AsciiString (V3d_View::*)() const) &V3d_View::StatisticInformation, "Returns string with statistic performance info.");
cls_V3d_View.def("StatisticInformation", (void (V3d_View::*)(TColStd_IndexedDataMapOfStringString &) const) &V3d_View::StatisticInformation, "Fills in the dictionary with statistic performance info.", py::arg("theDict"));
cls_V3d_View.def("GravityPoint", (gp_Pnt (V3d_View::*)() const) &V3d_View::GravityPoint, "Returns the Objects number and the gravity center of ALL viewable points in the view");
cls_V3d_View.def_static("get_type_name_", (const char * (*)()) &V3d_View::get_type_name, "None");
cls_V3d_View.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_View::get_type_descriptor, "None");
cls_V3d_View.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_View::*)() const) &V3d_View::DynamicType, "None");

// CLASS: V3D
py::class_<V3d> cls_V3d(mod, "V3d", "This package contains the set of commands and services of the 3D Viewer. It provides a set of high level commands to control the views and viewing modes.");

// Constructors
cls_V3d.def(py::init<>());

// Methods
// cls_V3d.def_static("operator new_", (void * (*)(size_t)) &V3d::operator new, "None", py::arg("theSize"));
// cls_V3d.def_static("operator delete_", (void (*)(void *)) &V3d::operator delete, "None", py::arg("theAddress"));
// cls_V3d.def_static("operator new[]_", (void * (*)(size_t)) &V3d::operator new[], "None", py::arg("theSize"));
// cls_V3d.def_static("operator delete[]_", (void (*)(void *)) &V3d::operator delete[], "None", py::arg("theAddress"));
// cls_V3d.def_static("operator new_", (void * (*)(size_t, void *)) &V3d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_V3d.def_static("operator delete_", (void (*)(void *, void *)) &V3d::operator delete, "None", py::arg(""), py::arg(""));
cls_V3d.def_static("GetProjAxis_", (gp_Dir (*)(const V3d_TypeOfOrientation)) &V3d::GetProjAxis, "Determines the orientation vector corresponding to the predefined orientation type.", py::arg("theOrientation"));
cls_V3d.def_static("ArrowOfRadius_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d::ArrowOfRadius, "Compute the graphic structure of arrow. X0,Y0,Z0 : coordinate of the arrow. DX,DY,DZ : Direction of the arrow. Alpha : Angle of arrow. Lng : Length of arrow.", py::arg("garrow"), py::arg("X0"), py::arg("Y0"), py::arg("Z0"), py::arg("DX"), py::arg("DY"), py::arg("DZ"), py::arg("Alpha"), py::arg("Lng"));
cls_V3d.def_static("CircleInPlane_", (void (*)(const opencascade::handle<Graphic3d_Group> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d::CircleInPlane, "Compute the graphic structure of circle. X0,Y0,Z0 : Center of circle. VX,VY,VZ : Axis of circle. Radius : Radius of circle.", py::arg("gcircle"), py::arg("X0"), py::arg("Y0"), py::arg("Z0"), py::arg("VX"), py::arg("VY"), py::arg("VZ"), py::arg("Radius"));
cls_V3d.def_static("SwitchViewsinWindow_", (void (*)(const opencascade::handle<V3d_View> &, const opencascade::handle<V3d_View> &)) &V3d::SwitchViewsinWindow, "None", py::arg("aPreviousView"), py::arg("aNextView"));
cls_V3d.def_static("TypeOfOrientationToString_", (Standard_CString (*)(V3d_TypeOfOrientation)) &V3d::TypeOfOrientationToString, "Returns the string name for a given orientation type.", py::arg("theType"));
cls_V3d.def_static("TypeOfOrientationFromString_", (V3d_TypeOfOrientation (*)(Standard_CString)) &V3d::TypeOfOrientationFromString, "Returns the orientation type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"));
cls_V3d.def_static("TypeOfOrientationFromString_", (Standard_Boolean (*)(const Standard_CString, V3d_TypeOfOrientation &)) &V3d::TypeOfOrientationFromString, "Determines the shape type from the given string identifier (using case-insensitive comparison).", py::arg("theTypeString"), py::arg("theType"));

// CLASS: V3D_AMBIENTLIGHT
py::class_<V3d_AmbientLight, opencascade::handle<V3d_AmbientLight>, Graphic3d_CLight> cls_V3d_AmbientLight(mod, "V3d_AmbientLight", "Creation of an ambient light source in a viewer.");

// Constructors
cls_V3d_AmbientLight.def(py::init<>());
cls_V3d_AmbientLight.def(py::init<const Quantity_Color &>(), py::arg("theColor"));
cls_V3d_AmbientLight.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("theViewer"));
cls_V3d_AmbientLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theColor"));

// Methods
cls_V3d_AmbientLight.def_static("get_type_name_", (const char * (*)()) &V3d_AmbientLight::get_type_name, "None");
cls_V3d_AmbientLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_AmbientLight::get_type_descriptor, "None");
cls_V3d_AmbientLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_AmbientLight::*)() const) &V3d_AmbientLight::DynamicType, "None");

// CLASS: V3D_BADVALUE
py::class_<V3d_BadValue, opencascade::handle<V3d_BadValue>, Standard_OutOfRange> cls_V3d_BadValue(mod, "V3d_BadValue", "None");

// Constructors
cls_V3d_BadValue.def(py::init<>());
cls_V3d_BadValue.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_V3d_BadValue.def_static("Raise_", (void (*)(const Standard_CString)) &V3d_BadValue::Raise, "None", py::arg("theMessage"));
cls_V3d_BadValue.def_static("Raise_", (void (*)(Standard_SStream &)) &V3d_BadValue::Raise, "None", py::arg("theMessage"));
cls_V3d_BadValue.def_static("NewInstance_", (opencascade::handle<V3d_BadValue> (*)(const Standard_CString)) &V3d_BadValue::NewInstance, "None", py::arg("theMessage"));
cls_V3d_BadValue.def_static("get_type_name_", (const char * (*)()) &V3d_BadValue::get_type_name, "None");
cls_V3d_BadValue.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_BadValue::get_type_descriptor, "None");
cls_V3d_BadValue.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_BadValue::*)() const) &V3d_BadValue::DynamicType, "None");

// CLASS: V3D_CIRCULARGRID
py::class_<V3d_CircularGrid, opencascade::handle<V3d_CircularGrid>, Aspect_CircularGrid> cls_V3d_CircularGrid(mod, "V3d_CircularGrid", "None");

// Constructors
cls_V3d_CircularGrid.def(py::init<const V3d_ViewerPointer &, const Quantity_Color &, const Quantity_Color &>(), py::arg("aViewer"), py::arg("aColor"), py::arg("aTenthColor"));

// Methods
cls_V3d_CircularGrid.def_static("get_type_name_", (const char * (*)()) &V3d_CircularGrid::get_type_name, "None");
cls_V3d_CircularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_CircularGrid::get_type_descriptor, "None");
cls_V3d_CircularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_CircularGrid::*)() const) &V3d_CircularGrid::DynamicType, "None");
cls_V3d_CircularGrid.def("SetColors", (void (V3d_CircularGrid::*)(const Quantity_Color &, const Quantity_Color &)) &V3d_CircularGrid::SetColors, "None", py::arg("aColor"), py::arg("aTenthColor"));
cls_V3d_CircularGrid.def("Display", (void (V3d_CircularGrid::*)()) &V3d_CircularGrid::Display, "None");
cls_V3d_CircularGrid.def("Erase", (void (V3d_CircularGrid::*)() const) &V3d_CircularGrid::Erase, "None");
cls_V3d_CircularGrid.def("IsDisplayed", (Standard_Boolean (V3d_CircularGrid::*)() const) &V3d_CircularGrid::IsDisplayed, "None");
cls_V3d_CircularGrid.def("GraphicValues", [](V3d_CircularGrid &self, Standard_Real & Radius, Standard_Real & OffSet){ self.GraphicValues(Radius, OffSet); return std::tuple<Standard_Real &, Standard_Real &>(Radius, OffSet); }, "None", py::arg("Radius"), py::arg("OffSet"));
cls_V3d_CircularGrid.def("SetGraphicValues", (void (V3d_CircularGrid::*)(const Standard_Real, const Standard_Real)) &V3d_CircularGrid::SetGraphicValues, "None", py::arg("Radius"), py::arg("OffSet"));

// TYPEDEF: V3D_COORDINATE

// CLASS: V3D_POSITIONLIGHT
py::class_<V3d_PositionLight, opencascade::handle<V3d_PositionLight>, Graphic3d_CLight> cls_V3d_PositionLight(mod, "V3d_PositionLight", "Base class for Positional, Spot and Directional Light classes.");

// Methods
cls_V3d_PositionLight.def_static("get_type_name_", (const char * (*)()) &V3d_PositionLight::get_type_name, "None");
cls_V3d_PositionLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_PositionLight::get_type_descriptor, "None");
cls_V3d_PositionLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_PositionLight::*)() const) &V3d_PositionLight::DynamicType, "None");

// CLASS: V3D_DIRECTIONALLIGHT
py::class_<V3d_DirectionalLight, opencascade::handle<V3d_DirectionalLight>, V3d_PositionLight> cls_V3d_DirectionalLight(mod, "V3d_DirectionalLight", "Directional light source for a viewer.");

// Constructors
cls_V3d_DirectionalLight.def(py::init<>());
cls_V3d_DirectionalLight.def(py::init<const V3d_TypeOfOrientation>(), py::arg("theDirection"));
cls_V3d_DirectionalLight.def(py::init<const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Boolean>(), py::arg("theDirection"), py::arg("theColor"), py::arg("theIsHeadlight"));
cls_V3d_DirectionalLight.def(py::init<const gp_Dir &>(), py::arg("theDirection"));
cls_V3d_DirectionalLight.def(py::init<const gp_Dir &, const Quantity_Color &>(), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const gp_Dir &, const Quantity_Color &, const Standard_Boolean>(), py::arg("theDirection"), py::arg("theColor"), py::arg("theIsHeadlight"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &>(), py::arg("theViewer"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfOrientation>(), py::arg("theViewer"), py::arg("theDirection"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Boolean>(), py::arg("theViewer"), py::arg("theDirection"), py::arg("theColor"), py::arg("theIsHeadlight"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"));
cls_V3d_DirectionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Boolean>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theIsHeadlight"));

// Methods
cls_V3d_DirectionalLight.def_static("get_type_name_", (const char * (*)()) &V3d_DirectionalLight::get_type_name, "None");
cls_V3d_DirectionalLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_DirectionalLight::get_type_descriptor, "None");
cls_V3d_DirectionalLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_DirectionalLight::*)() const) &V3d_DirectionalLight::DynamicType, "None");
cls_V3d_DirectionalLight.def("SetDirection", (void (V3d_DirectionalLight::*)(V3d_TypeOfOrientation)) &V3d_DirectionalLight::SetDirection, "Defines the direction of the light source by a predefined orientation.", py::arg("theDirection"));

// TYPEDEF: V3D_PARAMETER

// CLASS: V3D_PLANE
py::class_<V3d_Plane, opencascade::handle<V3d_Plane>, Standard_Transient> cls_V3d_Plane(mod, "V3d_Plane", "Obsolete clip plane presentation class. Ported on new core of Graphic3d_ClipPlane approach. Please access Graphic3d_ClipPlane via ClipPlane() method to use it for standard clipping workflow. Example of use:");

// Constructors
cls_V3d_Plane.def(py::init<>());
cls_V3d_Plane.def(py::init<const Standard_Real>(), py::arg("theA"));
cls_V3d_Plane.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("theA"), py::arg("theB"));
cls_V3d_Plane.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theA"), py::arg("theB"), py::arg("theC"));
cls_V3d_Plane.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theA"), py::arg("theB"), py::arg("theC"), py::arg("theD"));

// Methods
cls_V3d_Plane.def("SetPlane", (void (V3d_Plane::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_Plane::SetPlane, "Change plane equation.", py::arg("theA"), py::arg("theB"), py::arg("theC"), py::arg("theD"));
cls_V3d_Plane.def("Display", [](V3d_Plane &self, const opencascade::handle<V3d_View> & a0) -> void { return self.Display(a0); });
cls_V3d_Plane.def("Display", (void (V3d_Plane::*)(const opencascade::handle<V3d_View> &, const Quantity_Color &)) &V3d_Plane::Display, "Display the plane representation in the choosen view.", py::arg("theView"), py::arg("theColor"));
cls_V3d_Plane.def("Erase", (void (V3d_Plane::*)()) &V3d_Plane::Erase, "Erase the plane representation.");
cls_V3d_Plane.def("Plane", [](V3d_Plane &self, Standard_Real & theA, Standard_Real & theB, Standard_Real & theC, Standard_Real & theD){ self.Plane(theA, theB, theC, theD); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(theA, theB, theC, theD); }, "Returns the parameters of the plane.", py::arg("theA"), py::arg("theB"), py::arg("theC"), py::arg("theD"));
cls_V3d_Plane.def("IsDisplayed", (Standard_Boolean (V3d_Plane::*)() const) &V3d_Plane::IsDisplayed, "Returns TRUE when the plane representation is displayed.");
cls_V3d_Plane.def("ClipPlane", (const opencascade::handle<Graphic3d_ClipPlane> & (V3d_Plane::*)() const) &V3d_Plane::ClipPlane, "Use this method to pass clipping plane implementation for standard clipping workflow.");
cls_V3d_Plane.def_static("get_type_name_", (const char * (*)()) &V3d_Plane::get_type_name, "None");
cls_V3d_Plane.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_Plane::get_type_descriptor, "None");
cls_V3d_Plane.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_Plane::*)() const) &V3d_Plane::DynamicType, "None");

// CLASS: V3D_POSITIONALLIGHT
py::class_<V3d_PositionalLight, opencascade::handle<V3d_PositionalLight>, V3d_PositionLight> cls_V3d_PositionalLight(mod, "V3d_PositionalLight", "Creation and modification of an isolated (positional) light source. It is also defined by the color and two attenuation factors ConstAttentuation() and LinearAttentuation(). The resulting attenuation factor determining the illumination of a surface depends on the following formula: Where Distance is the distance of the isolated source from the surface.");

// Constructors
cls_V3d_PositionalLight.def(py::init<const gp_Pnt &>(), py::arg("thePos"));
cls_V3d_PositionalLight.def(py::init<const gp_Pnt &, const Quantity_Color &>(), py::arg("thePos"), py::arg("theColor"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theColor"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theColor"), py::arg("theConstAttenuation"));
cls_V3d_PositionalLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));

// Methods
cls_V3d_PositionalLight.def_static("get_type_name_", (const char * (*)()) &V3d_PositionalLight::get_type_name, "None");
cls_V3d_PositionalLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_PositionalLight::get_type_descriptor, "None");
cls_V3d_PositionalLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_PositionalLight::*)() const) &V3d_PositionalLight::DynamicType, "None");

// CLASS: V3D_RECTANGULARGRID
py::class_<V3d_RectangularGrid, opencascade::handle<V3d_RectangularGrid>, Aspect_RectangularGrid> cls_V3d_RectangularGrid(mod, "V3d_RectangularGrid", "None");

// Constructors
cls_V3d_RectangularGrid.def(py::init<const V3d_ViewerPointer &, const Quantity_Color &, const Quantity_Color &>(), py::arg("aViewer"), py::arg("aColor"), py::arg("aTenthColor"));

// Methods
cls_V3d_RectangularGrid.def_static("get_type_name_", (const char * (*)()) &V3d_RectangularGrid::get_type_name, "None");
cls_V3d_RectangularGrid.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_RectangularGrid::get_type_descriptor, "None");
cls_V3d_RectangularGrid.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_RectangularGrid::*)() const) &V3d_RectangularGrid::DynamicType, "None");
cls_V3d_RectangularGrid.def("SetColors", (void (V3d_RectangularGrid::*)(const Quantity_Color &, const Quantity_Color &)) &V3d_RectangularGrid::SetColors, "None", py::arg("aColor"), py::arg("aTenthColor"));
cls_V3d_RectangularGrid.def("Display", (void (V3d_RectangularGrid::*)()) &V3d_RectangularGrid::Display, "None");
cls_V3d_RectangularGrid.def("Erase", (void (V3d_RectangularGrid::*)() const) &V3d_RectangularGrid::Erase, "None");
cls_V3d_RectangularGrid.def("IsDisplayed", (Standard_Boolean (V3d_RectangularGrid::*)() const) &V3d_RectangularGrid::IsDisplayed, "None");
cls_V3d_RectangularGrid.def("GraphicValues", [](V3d_RectangularGrid &self, Standard_Real & XSize, Standard_Real & YSize, Standard_Real & OffSet){ self.GraphicValues(XSize, YSize, OffSet); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(XSize, YSize, OffSet); }, "None", py::arg("XSize"), py::arg("YSize"), py::arg("OffSet"));
cls_V3d_RectangularGrid.def("SetGraphicValues", (void (V3d_RectangularGrid::*)(const Standard_Real, const Standard_Real, const Standard_Real)) &V3d_RectangularGrid::SetGraphicValues, "None", py::arg("XSize"), py::arg("YSize"), py::arg("OffSet"));

// CLASS: V3D_SPOTLIGHT
py::class_<V3d_SpotLight, opencascade::handle<V3d_SpotLight>, V3d_PositionLight> cls_V3d_SpotLight(mod, "V3d_SpotLight", "Creation and modification of a spot. The attenuation factor F determines the illumination of a surface: Where Distance is the distance from the source to the surface. The default values (1.0, 0.0) correspond to a minimum of attenuation. The concentration factor determines the dispersion of the light on the surface, the default value (1.0) corresponds to a minimum of dispersion.");

// Constructors
cls_V3d_SpotLight.def(py::init<const gp_Pnt &>(), py::arg("thePos"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const V3d_TypeOfOrientation>(), py::arg("thePos"), py::arg("theDirection"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("thePos"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const gp_Dir &>(), py::arg("thePos"), py::arg("theDirection"));
cls_V3d_SpotLight.def(py::init<const gp_Pnt &, const gp_Dir &, const Quantity_Color &>(), py::arg("thePos"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const V3d_TypeOfOrientation, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theX"), py::arg("theY"), py::arg("theZ"), py::arg("theDirection"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"), py::arg("theAngle"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"));
cls_V3d_SpotLight.def(py::init<const opencascade::handle<V3d_Viewer> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_Color &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("theViewer"), py::arg("theXt"), py::arg("theYt"), py::arg("theZt"), py::arg("theXp"), py::arg("theYp"), py::arg("theZp"), py::arg("theColor"), py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"), py::arg("theConcentration"), py::arg("theAngle"));

// Methods
cls_V3d_SpotLight.def_static("get_type_name_", (const char * (*)()) &V3d_SpotLight::get_type_name, "None");
cls_V3d_SpotLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_SpotLight::get_type_descriptor, "None");
cls_V3d_SpotLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_SpotLight::*)() const) &V3d_SpotLight::DynamicType, "None");
cls_V3d_SpotLight.def("SetDirection", (void (V3d_SpotLight::*)(V3d_TypeOfOrientation)) &V3d_SpotLight::SetDirection, "Defines the direction of the light source according to a predefined directional vector.", py::arg("theOrientation"));

// TYPEDEF: V3D_TYPEOFSHADINGMODEL

// CLASS: V3D_UNMAPPED
py::class_<V3d_UnMapped, opencascade::handle<V3d_UnMapped>, Standard_DomainError> cls_V3d_UnMapped(mod, "V3d_UnMapped", "None");

// Constructors
cls_V3d_UnMapped.def(py::init<>());
cls_V3d_UnMapped.def(py::init<const Standard_CString>(), py::arg("theMessage"));

// Methods
cls_V3d_UnMapped.def_static("Raise_", (void (*)(const Standard_CString)) &V3d_UnMapped::Raise, "None", py::arg("theMessage"));
cls_V3d_UnMapped.def_static("Raise_", (void (*)(Standard_SStream &)) &V3d_UnMapped::Raise, "None", py::arg("theMessage"));
cls_V3d_UnMapped.def_static("NewInstance_", (opencascade::handle<V3d_UnMapped> (*)(const Standard_CString)) &V3d_UnMapped::NewInstance, "None", py::arg("theMessage"));
cls_V3d_UnMapped.def_static("get_type_name_", (const char * (*)()) &V3d_UnMapped::get_type_name, "None");
cls_V3d_UnMapped.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &V3d_UnMapped::get_type_descriptor, "None");
cls_V3d_UnMapped.def("DynamicType", (const opencascade::handle<Standard_Type> & (V3d_UnMapped::*)() const) &V3d_UnMapped::DynamicType, "None");

// TYPEDEF: V3D_VIEWPOINTER


}
