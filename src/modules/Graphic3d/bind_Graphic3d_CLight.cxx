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
#include <Graphic3d_CLight.hxx>
#include <Standard_Type.hxx>
#include <Graphic3d_TypeOfLightSource.hxx>
#include <TCollection_AsciiString.hxx>
#include <Quantity_Color.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt.hxx>
#include <gp_Dir.hxx>
#include <Graphic3d_Vec4.hxx>
#include <Quantity_ColorRGBA.hxx>

void bind_Graphic3d_CLight(py::module &mod){

py::class_<Graphic3d_CLight, opencascade::handle<Graphic3d_CLight>, Standard_Transient> cls_Graphic3d_CLight(mod, "Graphic3d_CLight", "Generic light source definition. This class defines arbitrary light source - see Graphic3d_TypeOfLightSource enumeration. Some parameters are applicable only to particular light type; calling methods unrelated to current type will throw an exception.");

// Constructors
cls_Graphic3d_CLight.def(py::init<Graphic3d_TypeOfLightSource>(), py::arg("theType"));

// Fields

// Methods
cls_Graphic3d_CLight.def_static("get_type_name_", (const char * (*)()) &Graphic3d_CLight::get_type_name, "None");
cls_Graphic3d_CLight.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &Graphic3d_CLight::get_type_descriptor, "None");
cls_Graphic3d_CLight.def("DynamicType", (const opencascade::handle<Standard_Type> & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::DynamicType, "None");
cls_Graphic3d_CLight.def("Type", (Graphic3d_TypeOfLightSource (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Type, "Returns the Type of the Light, cannot be changed after object construction.");
cls_Graphic3d_CLight.def("Name", (const TCollection_AsciiString & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Name, "Returns light source name; empty string by default.");
cls_Graphic3d_CLight.def("SetName", (void (Graphic3d_CLight::*)(const TCollection_AsciiString &)) &Graphic3d_CLight::SetName, "Sets light source name.", py::arg("theName"));
cls_Graphic3d_CLight.def("Color", (const Quantity_Color & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Color, "Returns the color of the light source; WHITE by default.");
cls_Graphic3d_CLight.def("SetColor", (void (Graphic3d_CLight::*)(const Quantity_Color &)) &Graphic3d_CLight::SetColor, "Defines the color of a light source by giving the basic color.", py::arg("theColor"));
cls_Graphic3d_CLight.def("IsEnabled", (Standard_Boolean (Graphic3d_CLight::*)() const) &Graphic3d_CLight::IsEnabled, "Check that the light source is turned on; TRUE by default. This flag affects all occurrences of light sources, where it was registered and activated; so that it is possible defining an active light in View which is actually in disabled state.");
cls_Graphic3d_CLight.def("SetEnabled", (void (Graphic3d_CLight::*)(Standard_Boolean)) &Graphic3d_CLight::SetEnabled, "Change enabled state of the light state. This call does not remove or deactivate light source in Views/Viewers; instead it turns it OFF so that it just have no effect.", py::arg("theIsOn"));
cls_Graphic3d_CLight.def("IsHeadlight", (Standard_Boolean (Graphic3d_CLight::*)() const) &Graphic3d_CLight::IsHeadlight, "Returns true if the light is a headlight; FALSE by default. Headlight flag means that light position/direction are defined not in a World coordinate system, but relative to the camera orientation.");
cls_Graphic3d_CLight.def("Headlight", (Standard_Boolean (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Headlight, "Alias for IsHeadlight().");
cls_Graphic3d_CLight.def("SetHeadlight", (void (Graphic3d_CLight::*)(Standard_Boolean)) &Graphic3d_CLight::SetHeadlight, "Setup headlight flag.", py::arg("theValue"));
cls_Graphic3d_CLight.def("Position", (const gp_Pnt & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Position, "Returns location of positional/spot light; (0, 0, 0) by default.");
cls_Graphic3d_CLight.def("SetPosition", (void (Graphic3d_CLight::*)(const gp_Pnt &)) &Graphic3d_CLight::SetPosition, "Setup location of positional/spot light.", py::arg("thePosition"));
cls_Graphic3d_CLight.def("Position", [](Graphic3d_CLight &self, Standard_Real & theX, Standard_Real & theY, Standard_Real & theZ){ self.Position(theX, theY, theZ); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theX, theY, theZ); }, "Returns location of positional/spot light.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_CLight.def("SetPosition", (void (Graphic3d_CLight::*)(Standard_Real, Standard_Real, Standard_Real)) &Graphic3d_CLight::SetPosition, "Setup location of positional/spot light.", py::arg("theX"), py::arg("theY"), py::arg("theZ"));
cls_Graphic3d_CLight.def("ConstAttenuation", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::ConstAttenuation, "Returns constant attenuation factor of positional/spot light source; 1.0f by default. Distance attenuation factors of reducing positional/spot light intensity depending on the distance from its position:");
cls_Graphic3d_CLight.def("LinearAttenuation", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::LinearAttenuation, "Returns linear attenuation factor of positional/spot light source; 0.0 by default. Distance attenuation factors of reducing positional/spot light intensity depending on the distance from its position:");
cls_Graphic3d_CLight.def("Attenuation", [](Graphic3d_CLight &self, Standard_Real & theConstAttenuation, Standard_Real & theLinearAttenuation){ self.Attenuation(theConstAttenuation, theLinearAttenuation); return std::tuple<Standard_Real &, Standard_Real &>(theConstAttenuation, theLinearAttenuation); }, "Returns the attenuation factors.", py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_Graphic3d_CLight.def("SetAttenuation", (void (Graphic3d_CLight::*)(Standard_ShortReal, Standard_ShortReal)) &Graphic3d_CLight::SetAttenuation, "Defines the coefficients of attenuation; values should be >= 0.0 and their summ should not be equal to 0.", py::arg("theConstAttenuation"), py::arg("theLinearAttenuation"));
cls_Graphic3d_CLight.def("Direction", (gp_Dir (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Direction, "Returns direction of directional/spot light.");
cls_Graphic3d_CLight.def("SetDirection", (void (Graphic3d_CLight::*)(const gp_Dir &)) &Graphic3d_CLight::SetDirection, "Sets direction of directional/spot light.", py::arg("theDir"));
cls_Graphic3d_CLight.def("Direction", [](Graphic3d_CLight &self, Standard_Real & theVx, Standard_Real & theVy, Standard_Real & theVz){ self.Direction(theVx, theVy, theVz); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theVx, theVy, theVz); }, "Returns the theVx, theVy, theVz direction of the light source.", py::arg("theVx"), py::arg("theVy"), py::arg("theVz"));
cls_Graphic3d_CLight.def("SetDirection", (void (Graphic3d_CLight::*)(Standard_Real, Standard_Real, Standard_Real)) &Graphic3d_CLight::SetDirection, "Sets direction of directional/spot light.", py::arg("theVx"), py::arg("theVy"), py::arg("theVz"));
cls_Graphic3d_CLight.def("Angle", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Angle, "Returns an angle in radians of the cone created by the spot; 30 degrees by default.");
cls_Graphic3d_CLight.def("SetAngle", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetAngle, "Angle in radians of the cone created by the spot, should be within range (0.0, M_PI).", py::arg("theAngle"));
cls_Graphic3d_CLight.def("Concentration", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Concentration, "Returns intensity distribution of the spot light, within [0.0, 1.0] range; 1.0 by default. This coefficient should be converted into spotlight exponent within [0.0, 128.0] range: The concentration factor determines the dispersion of the light on the surface, the default value (1.0) corresponds to a minimum of dispersion.");
cls_Graphic3d_CLight.def("SetConcentration", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetConcentration, "Defines the coefficient of concentration; value should be within range [0.0, 1.0].", py::arg("theConcentration"));
cls_Graphic3d_CLight.def("Intensity", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Intensity, "Returns the intensity of light source; 1.0 by default.");
cls_Graphic3d_CLight.def("SetIntensity", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetIntensity, "Modifies the intensity of light source, which should be > 0.0.", py::arg("theValue"));
cls_Graphic3d_CLight.def("Smoothness", (Standard_ShortReal (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Smoothness, "Returns the smoothness of light source (either smoothing angle for directional light or smoothing radius in case of positional light); 0.0 by default.");
cls_Graphic3d_CLight.def("SetSmoothRadius", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetSmoothRadius, "Modifies the smoothing radius of positional/spot light; should be >= 0.0.", py::arg("theValue"));
cls_Graphic3d_CLight.def("SetSmoothAngle", (void (Graphic3d_CLight::*)(Standard_ShortReal)) &Graphic3d_CLight::SetSmoothAngle, "Modifies the smoothing angle (in radians) of directional light source; should be within range [0.0, M_PI/2].", py::arg("theValue"));
cls_Graphic3d_CLight.def("GetId", (const TCollection_AsciiString & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::GetId, "Returns light resource identifier string");
cls_Graphic3d_CLight.def("PackedParams", (const Graphic3d_Vec4 & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::PackedParams, "Packed light parameters.");
cls_Graphic3d_CLight.def("PackedColor", (const Graphic3d_Vec4 & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::PackedColor, "Returns the color of the light source with dummy Alpha component, which should be ignored.");
cls_Graphic3d_CLight.def("PackedDirection", (const Graphic3d_Vec4 & (Graphic3d_CLight::*)() const) &Graphic3d_CLight::PackedDirection, "Returns direction of directional/spot light.");
cls_Graphic3d_CLight.def("Revision", (Standard_Size (Graphic3d_CLight::*)() const) &Graphic3d_CLight::Revision, "Returns modification counter");

// Enums

}