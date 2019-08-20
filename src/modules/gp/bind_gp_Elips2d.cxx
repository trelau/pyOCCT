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
#include <gp_Ax2d.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax22d.hxx>
#include <gp_Pnt2d.hxx>
#include <gp_Elips2d.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Vec2d.hxx>

void bind_gp_Elips2d(py::module &mod){

py::class_<gp_Elips2d, std::unique_ptr<gp_Elips2d>> cls_gp_Elips2d(mod, "gp_Elips2d", "Describes an ellipse in the plane (2D space). An ellipse is defined by its major and minor radii and positioned in the plane with a coordinate system (a gp_Ax22d object) as follows: - the origin of the coordinate system is the center of the ellipse, - its 'X Direction' defines the major axis of the ellipse, and - its 'Y Direction' defines the minor axis of the ellipse. This coordinate system is the 'local coordinate system' of the ellipse. Its orientation (direct or indirect) gives an implicit orientation to the ellipse. In this coordinate system, the equation of the ellipse is: X*X / (MajorRadius**2) + Y*Y / (MinorRadius**2) = 1.0 See Also gce_MakeElips2d which provides functions for more complex ellipse constructions Geom2d_Ellipse which provides additional functions for constructing ellipses and works, in particular, with the parametric equations of ellipses");

// Constructors
cls_gp_Elips2d.def(py::init<>());
cls_gp_Elips2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"));
cls_gp_Elips2d.def(py::init<const gp_Ax2d &, const Standard_Real, const Standard_Real, const Standard_Boolean>(), py::arg("MajorAxis"), py::arg("MajorRadius"), py::arg("MinorRadius"), py::arg("Sense"));
cls_gp_Elips2d.def(py::init<const gp_Ax22d &, const Standard_Real, const Standard_Real>(), py::arg("A"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
// cls_gp_Elips2d.def_static("operator new_", (void * (*)(size_t)) &gp_Elips2d::operator new, "None", py::arg("theSize"));
// cls_gp_Elips2d.def_static("operator delete_", (void (*)(void *)) &gp_Elips2d::operator delete, "None", py::arg("theAddress"));
// cls_gp_Elips2d.def_static("operator new[]_", (void * (*)(size_t)) &gp_Elips2d::operator new[], "None", py::arg("theSize"));
// cls_gp_Elips2d.def_static("operator delete[]_", (void (*)(void *)) &gp_Elips2d::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Elips2d.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Elips2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Elips2d.def_static("operator delete_", (void (*)(void *, void *)) &gp_Elips2d::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Elips2d.def("SetLocation", (void (gp_Elips2d::*)(const gp_Pnt2d &)) &gp_Elips2d::SetLocation, "Modifies this ellipse, by redefining its local coordinate system so that - its origin becomes P.", py::arg("P"));
cls_gp_Elips2d.def("SetMajorRadius", (void (gp_Elips2d::*)(const Standard_Real)) &gp_Elips2d::SetMajorRadius, "Changes the value of the major radius. Raises ConstructionError if MajorRadius < MinorRadius.", py::arg("MajorRadius"));
cls_gp_Elips2d.def("SetMinorRadius", (void (gp_Elips2d::*)(const Standard_Real)) &gp_Elips2d::SetMinorRadius, "Changes the value of the minor radius. Raises ConstructionError if MajorRadius < MinorRadius or MinorRadius < 0.0", py::arg("MinorRadius"));
cls_gp_Elips2d.def("SetAxis", (void (gp_Elips2d::*)(const gp_Ax22d &)) &gp_Elips2d::SetAxis, "Modifies this ellipse, by redefining its local coordinate system so that it becomes A.", py::arg("A"));
cls_gp_Elips2d.def("SetXAxis", (void (gp_Elips2d::*)(const gp_Ax2d &)) &gp_Elips2d::SetXAxis, "Modifies this ellipse, by redefining its local coordinate system so that its origin and its 'X Direction' become those of the axis A. The 'Y Direction' is then recomputed. The orientation of the local coordinate system is not modified.", py::arg("A"));
cls_gp_Elips2d.def("SetYAxis", (void (gp_Elips2d::*)(const gp_Ax2d &)) &gp_Elips2d::SetYAxis, "Modifies this ellipse, by redefining its local coordinate system so that its origin and its 'Y Direction' become those of the axis A. The 'X Direction' is then recomputed. The orientation of the local coordinate system is not modified.", py::arg("A"));
cls_gp_Elips2d.def("Area", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Area, "Computes the area of the ellipse.");
cls_gp_Elips2d.def("Coefficients", [](gp_Elips2d &self, Standard_Real & A, Standard_Real & B, Standard_Real & C, Standard_Real & D, Standard_Real & E, Standard_Real & F){ self.Coefficients(A, B, C, D, E, F); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(A, B, C, D, E, F); }, "Returns the coefficients of the implicit equation of the ellipse. A * (X**2) + B * (Y**2) + 2*C*(X*Y) + 2*D*X + 2*E*Y + F = 0.", py::arg("A"), py::arg("B"), py::arg("C"), py::arg("D"), py::arg("E"), py::arg("F"));
cls_gp_Elips2d.def("Directrix1", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::Directrix1, "This directrix is the line normal to the XAxis of the ellipse in the local plane (Z = 0) at a distance d = MajorRadius / e from the center of the ellipse, where e is the eccentricity of the ellipse. This line is parallel to the 'YAxis'. The intersection point between directrix1 and the 'XAxis' is the location point of the directrix1. This point is on the positive side of the 'XAxis'.");
cls_gp_Elips2d.def("Directrix2", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the minor axis of the ellipse.");
cls_gp_Elips2d.def("Eccentricity", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Eccentricity, "Returns the eccentricity of the ellipse between 0.0 and 1.0 If f is the distance between the center of the ellipse and the Focus1 then the eccentricity e = f / MajorRadius. Returns 0 if MajorRadius = 0.");
cls_gp_Elips2d.def("Focal", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Focal, "Returns the distance between the center of the ellipse and focus1 or focus2.");
cls_gp_Elips2d.def("Focus1", (gp_Pnt2d (gp_Elips2d::*)() const) &gp_Elips2d::Focus1, "Returns the first focus of the ellipse. This focus is on the positive side of the major axis of the ellipse.");
cls_gp_Elips2d.def("Focus2", (gp_Pnt2d (gp_Elips2d::*)() const) &gp_Elips2d::Focus2, "Returns the second focus of the ellipse. This focus is on the negative side of the major axis of the ellipse.");
cls_gp_Elips2d.def("Location", (const gp_Pnt2d & (gp_Elips2d::*)() const) &gp_Elips2d::Location, "Returns the center of the ellipse.");
cls_gp_Elips2d.def("MajorRadius", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::MajorRadius, "Returns the major radius of the Ellipse.");
cls_gp_Elips2d.def("MinorRadius", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::MinorRadius, "Returns the minor radius of the Ellipse.");
cls_gp_Elips2d.def("Parameter", (Standard_Real (gp_Elips2d::*)() const) &gp_Elips2d::Parameter, "Returns p = (1 - e * e) * MajorRadius where e is the eccentricity of the ellipse. Returns 0 if MajorRadius = 0");
cls_gp_Elips2d.def("Axis", (const gp_Ax22d & (gp_Elips2d::*)() const) &gp_Elips2d::Axis, "Returns the major axis of the ellipse.");
cls_gp_Elips2d.def("XAxis", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::XAxis, "Returns the major axis of the ellipse.");
cls_gp_Elips2d.def("YAxis", (gp_Ax2d (gp_Elips2d::*)() const) &gp_Elips2d::YAxis, "Returns the minor axis of the ellipse. Reverses the direction of the circle.");
cls_gp_Elips2d.def("Reverse", (void (gp_Elips2d::*)()) &gp_Elips2d::Reverse, "None");
cls_gp_Elips2d.def("Reversed", (gp_Elips2d (gp_Elips2d::*)() const) &gp_Elips2d::Reversed, "None");
cls_gp_Elips2d.def("IsDirect", (Standard_Boolean (gp_Elips2d::*)() const) &gp_Elips2d::IsDirect, "Returns true if the local coordinate system is direct and false in the other case.");
cls_gp_Elips2d.def("Mirror", (void (gp_Elips2d::*)(const gp_Pnt2d &)) &gp_Elips2d::Mirror, "None", py::arg("P"));
cls_gp_Elips2d.def("Mirrored", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &) const) &gp_Elips2d::Mirrored, "Performs the symmetrical transformation of a ellipse with respect to the point P which is the center of the symmetry", py::arg("P"));
cls_gp_Elips2d.def("Mirror", (void (gp_Elips2d::*)(const gp_Ax2d &)) &gp_Elips2d::Mirror, "None", py::arg("A"));
cls_gp_Elips2d.def("Mirrored", (gp_Elips2d (gp_Elips2d::*)(const gp_Ax2d &) const) &gp_Elips2d::Mirrored, "Performs the symmetrical transformation of a ellipse with respect to an axis placement which is the axis of the symmetry.", py::arg("A"));
cls_gp_Elips2d.def("Rotate", (void (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Elips2d::Rotate, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Elips2d.def("Rotated", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Elips2d::Rotated, "None", py::arg("P"), py::arg("Ang"));
cls_gp_Elips2d.def("Scale", (void (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real)) &gp_Elips2d::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Elips2d.def("Scaled", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &, const Standard_Real) const) &gp_Elips2d::Scaled, "Scales a ellipse. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Elips2d.def("Transform", (void (gp_Elips2d::*)(const gp_Trsf2d &)) &gp_Elips2d::Transform, "None", py::arg("T"));
cls_gp_Elips2d.def("Transformed", (gp_Elips2d (gp_Elips2d::*)(const gp_Trsf2d &) const) &gp_Elips2d::Transformed, "Transforms an ellipse with the transformation T from class Trsf2d.", py::arg("T"));
cls_gp_Elips2d.def("Translate", (void (gp_Elips2d::*)(const gp_Vec2d &)) &gp_Elips2d::Translate, "None", py::arg("V"));
cls_gp_Elips2d.def("Translated", (gp_Elips2d (gp_Elips2d::*)(const gp_Vec2d &) const) &gp_Elips2d::Translated, "Translates a ellipse in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Elips2d.def("Translate", (void (gp_Elips2d::*)(const gp_Pnt2d &, const gp_Pnt2d &)) &gp_Elips2d::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Elips2d.def("Translated", (gp_Elips2d (gp_Elips2d::*)(const gp_Pnt2d &, const gp_Pnt2d &) const) &gp_Elips2d::Translated, "Translates a ellipse from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}