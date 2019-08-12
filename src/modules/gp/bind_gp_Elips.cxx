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
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Ax1.hxx>
#include <gp_Pnt.hxx>
#include <gp_Elips.hxx>
#include <gp_Trsf.hxx>
#include <gp_Vec.hxx>

void bind_gp_Elips(py::module &mod){

py::class_<gp_Elips, std::unique_ptr<gp_Elips, Deleter<gp_Elips>>> cls_gp_Elips(mod, "gp_Elips", "Describes an ellipse in 3D space. An ellipse is defined by its major and minor radii and positioned in space with a coordinate system (a gp_Ax2 object) as follows: - the origin of the coordinate system is the center of the ellipse, - its 'X Direction' defines the major axis of the ellipse, and - its 'Y Direction' defines the minor axis of the ellipse. Together, the origin, 'X Direction' and 'Y Direction' of this coordinate system define the plane of the ellipse. This coordinate system is the 'local coordinate system' of the ellipse. In this coordinate system, the equation of the ellipse is: X*X / (MajorRadius**2) + Y*Y / (MinorRadius**2) = 1.0 The 'main Direction' of the local coordinate system gives the normal vector to the plane of the ellipse. This vector gives an implicit orientation to the ellipse (definition of the trigonometric sense). We refer to the 'main Axis' of the local coordinate system as the 'Axis' of the ellipse. See Also gce_MakeElips which provides functions for more complex ellipse constructions Geom_Ellipse which provides additional functions for constructing ellipses and works, in particular, with the parametric equations of ellipses");

// Constructors
cls_gp_Elips.def(py::init<>());
cls_gp_Elips.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real>(), py::arg("A2"), py::arg("MajorRadius"), py::arg("MinorRadius"));

// Fields

// Methods
// cls_gp_Elips.def_static("operator new_", (void * (*)(size_t)) &gp_Elips::operator new, "None", py::arg("theSize"));
// cls_gp_Elips.def_static("operator delete_", (void (*)(void *)) &gp_Elips::operator delete, "None", py::arg("theAddress"));
// cls_gp_Elips.def_static("operator new[]_", (void * (*)(size_t)) &gp_Elips::operator new[], "None", py::arg("theSize"));
// cls_gp_Elips.def_static("operator delete[]_", (void (*)(void *)) &gp_Elips::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Elips.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Elips::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Elips.def_static("operator delete_", (void (*)(void *, void *)) &gp_Elips::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Elips.def("SetAxis", (void (gp_Elips::*)(const gp_Ax1 &)) &gp_Elips::SetAxis, "Changes the axis normal to the plane of the ellipse. It modifies the definition of this plane. The 'XAxis' and the 'YAxis' are recomputed. The local coordinate system is redefined so that: - its origin and 'main Direction' become those of the axis A1 (the 'X Direction' and 'Y Direction' are then recomputed in the same way as for any gp_Ax2), or Raises ConstructionError if the direction of A1 is parallel to the direction of the 'XAxis' of the ellipse.", py::arg("A1"));
cls_gp_Elips.def("SetLocation", (void (gp_Elips::*)(const gp_Pnt &)) &gp_Elips::SetLocation, "Modifies this ellipse, by redefining its local coordinate so that its origin becomes P.", py::arg("P"));
cls_gp_Elips.def("SetMajorRadius", (void (gp_Elips::*)(const Standard_Real)) &gp_Elips::SetMajorRadius, "The major radius of the ellipse is on the 'XAxis' (major axis) of the ellipse. Raises ConstructionError if MajorRadius < MinorRadius.", py::arg("MajorRadius"));
cls_gp_Elips.def("SetMinorRadius", (void (gp_Elips::*)(const Standard_Real)) &gp_Elips::SetMinorRadius, "The minor radius of the ellipse is on the 'YAxis' (minor axis) of the ellipse. Raises ConstructionError if MinorRadius > MajorRadius or MinorRadius < 0.", py::arg("MinorRadius"));
cls_gp_Elips.def("SetPosition", (void (gp_Elips::*)(const gp_Ax2 &)) &gp_Elips::SetPosition, "Modifies this ellipse, by redefining its local coordinate so that it becomes A2e.", py::arg("A2"));
cls_gp_Elips.def("Area", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Area, "Computes the area of the Ellipse.");
cls_gp_Elips.def("Axis", (const gp_Ax1 & (gp_Elips::*)() const) &gp_Elips::Axis, "Computes the axis normal to the plane of the ellipse.");
cls_gp_Elips.def("Directrix1", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::Directrix1, "Computes the first or second directrix of this ellipse. These are the lines, in the plane of the ellipse, normal to the major axis, at a distance equal to MajorRadius/e from the center of the ellipse, where e is the eccentricity of the ellipse. The first directrix (Directrix1) is on the positive side of the major axis. The second directrix (Directrix2) is on the negative side. The directrix is returned as an axis (gp_Ax1 object), the origin of which is situated on the 'X Axis' of the local coordinate system of this ellipse. Exceptions Standard_ConstructionError if the eccentricity is null (the ellipse has degenerated into a circle).");
cls_gp_Elips.def("Directrix2", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::Directrix2, "This line is obtained by the symmetrical transformation of 'Directrix1' with respect to the 'YAxis' of the ellipse. Exceptions Standard_ConstructionError if the eccentricity is null (the ellipse has degenerated into a circle).");
cls_gp_Elips.def("Eccentricity", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Eccentricity, "Returns the eccentricity of the ellipse between 0.0 and 1.0 If f is the distance between the center of the ellipse and the Focus1 then the eccentricity e = f / MajorRadius. Raises ConstructionError if MajorRadius = 0.0");
cls_gp_Elips.def("Focal", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Focal, "Computes the focal distance. It is the distance between the two focus focus1 and focus2 of the ellipse.");
cls_gp_Elips.def("Focus1", (gp_Pnt (gp_Elips::*)() const) &gp_Elips::Focus1, "Returns the first focus of the ellipse. This focus is on the positive side of the 'XAxis' of the ellipse.");
cls_gp_Elips.def("Focus2", (gp_Pnt (gp_Elips::*)() const) &gp_Elips::Focus2, "Returns the second focus of the ellipse. This focus is on the negative side of the 'XAxis' of the ellipse.");
cls_gp_Elips.def("Location", (const gp_Pnt & (gp_Elips::*)() const) &gp_Elips::Location, "Returns the center of the ellipse. It is the 'Location' point of the coordinate system of the ellipse.");
cls_gp_Elips.def("MajorRadius", (Standard_Real (gp_Elips::*)() const) &gp_Elips::MajorRadius, "Returns the major radius of the ellipse.");
cls_gp_Elips.def("MinorRadius", (Standard_Real (gp_Elips::*)() const) &gp_Elips::MinorRadius, "Returns the minor radius of the ellipse.");
cls_gp_Elips.def("Parameter", (Standard_Real (gp_Elips::*)() const) &gp_Elips::Parameter, "Returns p = (1 - e * e) * MajorRadius where e is the eccentricity of the ellipse. Returns 0 if MajorRadius = 0");
cls_gp_Elips.def("Position", (const gp_Ax2 & (gp_Elips::*)() const) &gp_Elips::Position, "Returns the coordinate system of the ellipse.");
cls_gp_Elips.def("XAxis", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::XAxis, "Returns the 'XAxis' of the ellipse whose origin is the center of this ellipse. It is the major axis of the ellipse.");
cls_gp_Elips.def("YAxis", (gp_Ax1 (gp_Elips::*)() const) &gp_Elips::YAxis, "Returns the 'YAxis' of the ellipse whose unit vector is the 'X Direction' or the 'Y Direction' of the local coordinate system of this ellipse. This is the minor axis of the ellipse.");
cls_gp_Elips.def("Mirror", (void (gp_Elips::*)(const gp_Pnt &)) &gp_Elips::Mirror, "None", py::arg("P"));
cls_gp_Elips.def("Mirrored", (gp_Elips (gp_Elips::*)(const gp_Pnt &) const) &gp_Elips::Mirrored, "Performs the symmetrical transformation of an ellipse with respect to the point P which is the center of the symmetry.", py::arg("P"));
cls_gp_Elips.def("Mirror", (void (gp_Elips::*)(const gp_Ax1 &)) &gp_Elips::Mirror, "None", py::arg("A1"));
cls_gp_Elips.def("Mirrored", (gp_Elips (gp_Elips::*)(const gp_Ax1 &) const) &gp_Elips::Mirrored, "Performs the symmetrical transformation of an ellipse with respect to an axis placement which is the axis of the symmetry.", py::arg("A1"));
cls_gp_Elips.def("Mirror", (void (gp_Elips::*)(const gp_Ax2 &)) &gp_Elips::Mirror, "None", py::arg("A2"));
cls_gp_Elips.def("Mirrored", (gp_Elips (gp_Elips::*)(const gp_Ax2 &) const) &gp_Elips::Mirrored, "Performs the symmetrical transformation of an ellipse with respect to a plane. The axis placement A2 locates the plane of the symmetry (Location, XDirection, YDirection).", py::arg("A2"));
cls_gp_Elips.def("Rotate", (void (gp_Elips::*)(const gp_Ax1 &, const Standard_Real)) &gp_Elips::Rotate, "None", py::arg("A1"), py::arg("Ang"));
cls_gp_Elips.def("Rotated", (gp_Elips (gp_Elips::*)(const gp_Ax1 &, const Standard_Real) const) &gp_Elips::Rotated, "Rotates an ellipse. A1 is the axis of the rotation. Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Elips.def("Scale", (void (gp_Elips::*)(const gp_Pnt &, const Standard_Real)) &gp_Elips::Scale, "None", py::arg("P"), py::arg("S"));
cls_gp_Elips.def("Scaled", (gp_Elips (gp_Elips::*)(const gp_Pnt &, const Standard_Real) const) &gp_Elips::Scaled, "Scales an ellipse. S is the scaling value.", py::arg("P"), py::arg("S"));
cls_gp_Elips.def("Transform", (void (gp_Elips::*)(const gp_Trsf &)) &gp_Elips::Transform, "None", py::arg("T"));
cls_gp_Elips.def("Transformed", (gp_Elips (gp_Elips::*)(const gp_Trsf &) const) &gp_Elips::Transformed, "Transforms an ellipse with the transformation T from class Trsf.", py::arg("T"));
cls_gp_Elips.def("Translate", (void (gp_Elips::*)(const gp_Vec &)) &gp_Elips::Translate, "None", py::arg("V"));
cls_gp_Elips.def("Translated", (gp_Elips (gp_Elips::*)(const gp_Vec &) const) &gp_Elips::Translated, "Translates an ellipse in the direction of the vector V. The magnitude of the translation is the vector's magnitude.", py::arg("V"));
cls_gp_Elips.def("Translate", (void (gp_Elips::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Elips::Translate, "None", py::arg("P1"), py::arg("P2"));
cls_gp_Elips.def("Translated", (gp_Elips (gp_Elips::*)(const gp_Pnt &, const gp_Pnt &) const) &gp_Elips::Translated, "Translates an ellipse from the point P1 to the point P2.", py::arg("P1"), py::arg("P2"));

// Enums

}