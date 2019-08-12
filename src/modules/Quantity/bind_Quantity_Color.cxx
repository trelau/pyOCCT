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
#include <Standard.hxx>
#include <Quantity_NameOfColor.hxx>
#include <Standard_TypeDef.hxx>
#include <Quantity_TypeOfColor.hxx>
#include <NCollection_Vec3.hxx>
#include <Quantity_Color.hxx>

void bind_Quantity_Color(py::module &mod){

py::class_<Quantity_Color, std::unique_ptr<Quantity_Color, Deleter<Quantity_Color>>> cls_Quantity_Color(mod, "Quantity_Color", "This class allows the definition of a colour. The names of the colours are from the X11 specification. color object may be used for numerous applicative purposes. A color is defined by: - its respective quantities of red, green and blue (R-G-B values), or - its hue angle and its values of lightness and saturation (H-L-S values). These two color definition systems are equivalent. Use this class in conjunction with: - the Quantity_TypeOfColor enumeration which identifies the color definition system you are using, - the Quantity_NameOfColor enumeration which lists numerous predefined colors and identifies them by their name.");

// Constructors
cls_Quantity_Color.def(py::init<>());
cls_Quantity_Color.def(py::init<const Quantity_NameOfColor>(), py::arg("AName"));
cls_Quantity_Color.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_TypeOfColor>(), py::arg("theR1"), py::arg("theR2"), py::arg("theR3"), py::arg("theType"));
cls_Quantity_Color.def(py::init<const NCollection_Vec3<float> &>(), py::arg("theRgb"));

// Fields

// Methods
// cls_Quantity_Color.def_static("operator new_", (void * (*)(size_t)) &Quantity_Color::operator new, "None", py::arg("theSize"));
// cls_Quantity_Color.def_static("operator delete_", (void (*)(void *)) &Quantity_Color::operator delete, "None", py::arg("theAddress"));
// cls_Quantity_Color.def_static("operator new[]_", (void * (*)(size_t)) &Quantity_Color::operator new[], "None", py::arg("theSize"));
// cls_Quantity_Color.def_static("operator delete[]_", (void (*)(void *)) &Quantity_Color::operator delete[], "None", py::arg("theAddress"));
// cls_Quantity_Color.def_static("operator new_", (void * (*)(size_t, void *)) &Quantity_Color::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_Quantity_Color.def_static("operator delete_", (void (*)(void *, void *)) &Quantity_Color::operator delete, "None", py::arg(""), py::arg(""));
cls_Quantity_Color.def("ChangeContrast", (void (Quantity_Color::*)(const Standard_Real)) &Quantity_Color::ChangeContrast, "Increases or decreases the contrast by <ADelta>. <ADelta> is a percentage. Any value greater than zero will increase the contrast. The variation is expressed as a percentage of the current value. It is a variation of the saturation.", py::arg("ADelta"));
cls_Quantity_Color.def("ChangeIntensity", (void (Quantity_Color::*)(const Standard_Real)) &Quantity_Color::ChangeIntensity, "Increases or decreases the intensity by <ADelta>. <ADelta> is a percentage. Any value greater than zero will increase the intensity. The variation is expressed as a percentage of the current value. It is a variation of the lightness.", py::arg("ADelta"));
cls_Quantity_Color.def("SetValues", (void (Quantity_Color::*)(const Quantity_NameOfColor)) &Quantity_Color::SetValues, "Updates the colour <me> from the definition of the colour <AName>.", py::arg("AName"));
cls_Quantity_Color.def("SetValues", (void (Quantity_Color::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Quantity_TypeOfColor)) &Quantity_Color::SetValues, "Updates a color according to the mode specified by theType. TOC_RGB: - theR1 the value of Red within range [0.0; 1.0] - theR2 the value of Green within range [0.0; 1.0] - theR3 the value of Blue within range [0.0; 1.0]", py::arg("theR1"), py::arg("theR2"), py::arg("theR3"), py::arg("theType"));
cls_Quantity_Color.def("Delta", [](Quantity_Color &self, const Quantity_Color & AColor, Standard_Real & DC, Standard_Real & DI){ self.Delta(AColor, DC, DI); return std::tuple<Standard_Real &, Standard_Real &>(DC, DI); }, "Returns the percentage change of contrast and intensity between <me> and <AColor>. <DC> and <DI> are percentages, either positive or negative. The calculation is with respect to the current value of <me> If <DC> is positive then <me> is more contrasty. If <DI> is positive then <me> is more intense.", py::arg("AColor"), py::arg("DC"), py::arg("DI"));
cls_Quantity_Color.def("Distance", (Standard_Real (Quantity_Color::*)(const Quantity_Color &) const) &Quantity_Color::Distance, "Returns the distance between two colours. It's a value between 0 and the square root of 3 (the black/white distance)", py::arg("AColor"));
cls_Quantity_Color.def("SquareDistance", (Standard_Real (Quantity_Color::*)(const Quantity_Color &) const) &Quantity_Color::SquareDistance, "Returns the square of distance between two colours.", py::arg("AColor"));
cls_Quantity_Color.def("Blue", (Standard_Real (Quantity_Color::*)() const) &Quantity_Color::Blue, "Returns the Blue component (quantity of blue) of the color within range [0.0; 1.0].");
cls_Quantity_Color.def("Green", (Standard_Real (Quantity_Color::*)() const) &Quantity_Color::Green, "Returns the Green component (quantity of green) of the color within range [0.0; 1.0].");
cls_Quantity_Color.def("Hue", (Standard_Real (Quantity_Color::*)() const) &Quantity_Color::Hue, "Returns the Hue component (hue angle) of the color in degrees within range [0.0; 360.0], 0.0 being Red. -1.0 is a special value reserved for grayscale color (S should be 0.0)");
cls_Quantity_Color.def("IsDifferent", (Standard_Boolean (Quantity_Color::*)(const Quantity_Color &) const) &Quantity_Color::IsDifferent, "Returns Standard_True if the distance between <me> and <Other> is greater than Epsilon ().", py::arg("Other"));
cls_Quantity_Color.def("__ne__", (Standard_Boolean (Quantity_Color::*)(const Quantity_Color &) const) &Quantity_Color::operator!=, py::is_operator(), "None", py::arg("Other"));
cls_Quantity_Color.def("IsEqual", (Standard_Boolean (Quantity_Color::*)(const Quantity_Color &) const) &Quantity_Color::IsEqual, "Returns true if the Other color is - different from, or - equal to this color. Two colors are considered to be equal if their distance is no greater than Epsilon(). These methods are aliases of operator != and operator ==.", py::arg("Other"));
cls_Quantity_Color.def("__eq__", (Standard_Boolean (Quantity_Color::*)(const Quantity_Color &) const) &Quantity_Color::operator==, py::is_operator(), "None", py::arg("Other"));
cls_Quantity_Color.def("Light", (Standard_Real (Quantity_Color::*)() const) &Quantity_Color::Light, "Returns the Light component (value of the lightness) of the color within range [0.0; 1.0].");
cls_Quantity_Color.def("Name", (Quantity_NameOfColor (Quantity_Color::*)() const) &Quantity_Color::Name, "Returns the name of the color defined by its quantities of red R, green G and blue B; more precisely this is the nearest color from the Quantity_NameOfColor enumeration. Exceptions Standard_OutOfRange if R, G or B is less than 0. or greater than 1.");
cls_Quantity_Color.def("Red", (Standard_Real (Quantity_Color::*)() const) &Quantity_Color::Red, "Returns the Red component (quantity of red) of the color within range [0.0; 1.0].");
cls_Quantity_Color.def("Saturation", (Standard_Real (Quantity_Color::*)() const) &Quantity_Color::Saturation, "Returns the Saturation component (value of the saturation) of the color within range [0.0; 1.0].");
cls_Quantity_Color.def("Values", [](Quantity_Color &self, Standard_Real & theR1, Standard_Real & theR2, Standard_Real & theR3, const Quantity_TypeOfColor theType){ self.Values(theR1, theR2, theR3, theType); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(theR1, theR2, theR3); }, "Returns in theR1, theR2 and theR3 the components of this color according to the color system definition theType. If theType is Quantity_TOC_RGB: - theR1 the value of Red between 0.0 and 1.0 - theR2 the value of Green between 0.0 and 1.0 - theR3 the value of Blue between 0.0 and 1.0 If theType is Quantity_TOC_HLS: - theR1 is the Hue (H) angle in degrees within range [0.0; 360.0], 0.0 being Red. -1.0 is a special value reserved for grayscale color (S should be 0.0). - theR2 is the Lightness (L) within range [0.0; 1.0] - theR3 is the Saturation (S) within range [0.0; 1.0]", py::arg("theR1"), py::arg("theR2"), py::arg("theR3"), py::arg("theType"));
cls_Quantity_Color.def_static("SetEpsilon_", (void (*)(const Standard_Real)) &Quantity_Color::SetEpsilon, "Sets the specified value used to compare <me> and an other color in IsDifferent and in IsEqual methods. Warning: The default value is 0.0001", py::arg("AnEpsilon"));
cls_Quantity_Color.def_static("Epsilon_", (Standard_Real (*)()) &Quantity_Color::Epsilon, "Returns the specified value used to compare <me> and an other color in IsDifferent and in IsEqual methods.");
cls_Quantity_Color.def_static("Name_", (Quantity_NameOfColor (*)(const Standard_Real, const Standard_Real, const Standard_Real)) &Quantity_Color::Name, "Returns the name of the colour for which the RGB components are nearest to <R>, <G> and <B>.", py::arg("R"), py::arg("G"), py::arg("B"));
cls_Quantity_Color.def_static("StringName_", (Standard_CString (*)(const Quantity_NameOfColor)) &Quantity_Color::StringName, "Returns the name of the color identified by AName in the Quantity_NameOfColor enumeration. For example, the name of the color which corresponds to Quantity_NOC_BLACK is 'BLACK'. Exceptions Standard_OutOfRange if AName in not known in the Quantity_NameOfColor enumeration.", py::arg("AColor"));
cls_Quantity_Color.def_static("ColorFromName_", (Standard_Boolean (*)(const Standard_CString, Quantity_NameOfColor &)) &Quantity_Color::ColorFromName, "Finds color from predefined names. For example, the name of the color which corresponds to 'BLACK' is Quantity_NOC_BLACK. Returns false if name is unknown.", py::arg("theName"), py::arg("theColor"));
cls_Quantity_Color.def_static("HlsRgb_", [](const Standard_Real H, const Standard_Real L, const Standard_Real S, Standard_Real & R, Standard_Real & G, Standard_Real & B){ Quantity_Color::HlsRgb(H, L, S, R, G, B); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(R, G, B); }, "Converts HLS components into RGB ones.", py::arg("H"), py::arg("L"), py::arg("S"), py::arg("R"), py::arg("G"), py::arg("B"));
cls_Quantity_Color.def_static("RgbHls_", [](const Standard_Real R, const Standard_Real G, const Standard_Real B, Standard_Real & H, Standard_Real & L, Standard_Real & S){ Quantity_Color::RgbHls(R, G, B, H, L, S); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(H, L, S); }, "Converts RGB components into HLS ones.", py::arg("R"), py::arg("G"), py::arg("B"), py::arg("H"), py::arg("L"), py::arg("S"));
cls_Quantity_Color.def_static("Color2argb_", [](const Quantity_Color & theColor, Standard_Integer & theARGB){ Quantity_Color::Color2argb(theColor, theARGB); return theARGB; }, "Convert the Color value to ARGB integer value. theARGB has Alpha equal to zero, so the output is formatted as 0x00RRGGBB", py::arg("theColor"), py::arg("theARGB"));
cls_Quantity_Color.def_static("Argb2color_", (void (*)(const Standard_Integer, Quantity_Color &)) &Quantity_Color::Argb2color, "Convert integer ARGB value to Color. Alpha bits are ignored", py::arg("theARGB"), py::arg("theColor"));
cls_Quantity_Color.def_static("Test_", (void (*)()) &Quantity_Color::Test, "Internal test");

// Enums

}