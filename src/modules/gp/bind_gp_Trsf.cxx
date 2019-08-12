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
#include <gp_Trsf2d.hxx>
#include <gp_Pnt.hxx>
#include <gp_Ax1.hxx>
#include <gp_Ax2.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Quaternion.hxx>
#include <gp_Ax3.hxx>
#include <gp_Vec.hxx>
#include <gp_TrsfForm.hxx>
#include <gp_XYZ.hxx>
#include <gp_Mat.hxx>
#include <gp_Trsf.hxx>
#include <NCollection_Mat4.hxx>
#include <gp_GTrsf.hxx>

void bind_gp_Trsf(py::module &mod){

py::class_<gp_Trsf, std::unique_ptr<gp_Trsf, Deleter<gp_Trsf>>> cls_gp_Trsf(mod, "gp_Trsf", "Defines a non-persistent transformation in 3D space. The following transformations are implemented : . Translation, Rotation, Scale . Symmetry with respect to a point, a line, a plane. Complex transformations can be obtained by combining the previous elementary transformations using the method Multiply. The transformations can be represented as follow :");

// Constructors
cls_gp_Trsf.def(py::init<>());
cls_gp_Trsf.def(py::init<const gp_Trsf2d &>(), py::arg("T"));

// Fields

// Methods
// cls_gp_Trsf.def_static("operator new_", (void * (*)(size_t)) &gp_Trsf::operator new, "None", py::arg("theSize"));
// cls_gp_Trsf.def_static("operator delete_", (void (*)(void *)) &gp_Trsf::operator delete, "None", py::arg("theAddress"));
// cls_gp_Trsf.def_static("operator new[]_", (void * (*)(size_t)) &gp_Trsf::operator new[], "None", py::arg("theSize"));
// cls_gp_Trsf.def_static("operator delete[]_", (void (*)(void *)) &gp_Trsf::operator delete[], "None", py::arg("theAddress"));
// cls_gp_Trsf.def_static("operator new_", (void * (*)(size_t, void *)) &gp_Trsf::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_gp_Trsf.def_static("operator delete_", (void (*)(void *, void *)) &gp_Trsf::operator delete, "None", py::arg(""), py::arg(""));
cls_gp_Trsf.def("SetMirror", (void (gp_Trsf::*)(const gp_Pnt &)) &gp_Trsf::SetMirror, "Makes the transformation into a symmetrical transformation. P is the center of the symmetry.", py::arg("P"));
cls_gp_Trsf.def("SetMirror", (void (gp_Trsf::*)(const gp_Ax1 &)) &gp_Trsf::SetMirror, "Makes the transformation into a symmetrical transformation. A1 is the center of the axial symmetry.", py::arg("A1"));
cls_gp_Trsf.def("SetMirror", (void (gp_Trsf::*)(const gp_Ax2 &)) &gp_Trsf::SetMirror, "Makes the transformation into a symmetrical transformation. A2 is the center of the planar symmetry and defines the plane of symmetry by its origin, 'X Direction' and 'Y Direction'.", py::arg("A2"));
cls_gp_Trsf.def("SetRotation", (void (gp_Trsf::*)(const gp_Ax1 &, const Standard_Real)) &gp_Trsf::SetRotation, "Changes the transformation into a rotation. A1 is the rotation axis and Ang is the angular value of the rotation in radians.", py::arg("A1"), py::arg("Ang"));
cls_gp_Trsf.def("SetRotation", (void (gp_Trsf::*)(const gp_Quaternion &)) &gp_Trsf::SetRotation, "Changes the transformation into a rotation defined by quaternion. Note that rotation is performed around origin, i.e. no translation is involved.", py::arg("R"));
cls_gp_Trsf.def("SetScale", (void (gp_Trsf::*)(const gp_Pnt &, const Standard_Real)) &gp_Trsf::SetScale, "Changes the transformation into a scale. P is the center of the scale and S is the scaling value. Raises ConstructionError If <S> is null.", py::arg("P"), py::arg("S"));
cls_gp_Trsf.def("SetDisplacement", (void (gp_Trsf::*)(const gp_Ax3 &, const gp_Ax3 &)) &gp_Trsf::SetDisplacement, "Modifies this transformation so that it transforms the coordinate system defined by FromSystem1 into the one defined by ToSystem2. After this modification, this transformation transforms: - the origin of FromSystem1 into the origin of ToSystem2, - the 'X Direction' of FromSystem1 into the 'X Direction' of ToSystem2, - the 'Y Direction' of FromSystem1 into the 'Y Direction' of ToSystem2, and - the 'main Direction' of FromSystem1 into the 'main Direction' of ToSystem2. Warning When you know the coordinates of a point in one coordinate system and you want to express these coordinates in another one, do not use the transformation resulting from this function. Use the transformation that results from SetTransformation instead. SetDisplacement and SetTransformation create related transformations: the vectorial part of one is the inverse of the vectorial part of the other.", py::arg("FromSystem1"), py::arg("ToSystem2"));
cls_gp_Trsf.def("SetTransformation", (void (gp_Trsf::*)(const gp_Ax3 &, const gp_Ax3 &)) &gp_Trsf::SetTransformation, "Modifies this transformation so that it transforms the coordinates of any point, (x, y, z), relative to a source coordinate system into the coordinates (x', y', z') which are relative to a target coordinate system, but which represent the same point The transformation is from the coordinate system 'FromSystem1' to the coordinate system 'ToSystem2'. Example : In a C++ implementation : Real x1, y1, z1; // are the coordinates of a point in the // local system FromSystem1 Real x2, y2, z2; // are the coordinates of a point in the // local system ToSystem2 gp_Pnt P1 (x1, y1, z1) Trsf T; T.SetTransformation (FromSystem1, ToSystem2); gp_Pnt P2 = P1.Transformed (T); P2.Coord (x2, y2, z2);", py::arg("FromSystem1"), py::arg("ToSystem2"));
cls_gp_Trsf.def("SetTransformation", (void (gp_Trsf::*)(const gp_Ax3 &)) &gp_Trsf::SetTransformation, "Modifies this transformation so that it transforms the coordinates of any point, (x, y, z), relative to a source coordinate system into the coordinates (x', y', z') which are relative to a target coordinate system, but which represent the same point The transformation is from the default coordinate system {P(0.,0.,0.), VX (1.,0.,0.), VY (0.,1.,0.), VZ (0., 0. ,1.) } to the local coordinate system defined with the Ax3 ToSystem. Use in the same way as the previous method. FromSystem1 is defaulted to the absolute coordinate system.", py::arg("ToSystem"));
cls_gp_Trsf.def("SetTransformation", (void (gp_Trsf::*)(const gp_Quaternion &, const gp_Vec &)) &gp_Trsf::SetTransformation, "Sets transformation by directly specified rotation and translation.", py::arg("R"), py::arg("T"));
cls_gp_Trsf.def("SetTranslation", (void (gp_Trsf::*)(const gp_Vec &)) &gp_Trsf::SetTranslation, "Changes the transformation into a translation. V is the vector of the translation.", py::arg("V"));
cls_gp_Trsf.def("SetTranslation", (void (gp_Trsf::*)(const gp_Pnt &, const gp_Pnt &)) &gp_Trsf::SetTranslation, "Makes the transformation into a translation where the translation vector is the vector (P1, P2) defined from point P1 to point P2.", py::arg("P1"), py::arg("P2"));
cls_gp_Trsf.def("SetTranslationPart", (void (gp_Trsf::*)(const gp_Vec &)) &gp_Trsf::SetTranslationPart, "Replaces the translation vector with the vector V.", py::arg("V"));
cls_gp_Trsf.def("SetScaleFactor", (void (gp_Trsf::*)(const Standard_Real)) &gp_Trsf::SetScaleFactor, "Modifies the scale factor. Raises ConstructionError If S is null.", py::arg("S"));
cls_gp_Trsf.def("SetForm", (void (gp_Trsf::*)(const gp_TrsfForm)) &gp_Trsf::SetForm, "None", py::arg("P"));
cls_gp_Trsf.def("SetValues", (void (gp_Trsf::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &gp_Trsf::SetValues, "Sets the coefficients of the transformation. The transformation of the point x,y,z is the point x',y',z' with :", py::arg("a11"), py::arg("a12"), py::arg("a13"), py::arg("a14"), py::arg("a21"), py::arg("a22"), py::arg("a23"), py::arg("a24"), py::arg("a31"), py::arg("a32"), py::arg("a33"), py::arg("a34"));
cls_gp_Trsf.def("IsNegative", (Standard_Boolean (gp_Trsf::*)() const) &gp_Trsf::IsNegative, "Returns true if the determinant of the vectorial part of this transformation is negative.");
cls_gp_Trsf.def("Form", (gp_TrsfForm (gp_Trsf::*)() const) &gp_Trsf::Form, "Returns the nature of the transformation. It can be: an identity transformation, a rotation, a translation, a mirror transformation (relative to a point, an axis or a plane), a scaling transformation, or a compound transformation.");
cls_gp_Trsf.def("ScaleFactor", (Standard_Real (gp_Trsf::*)() const) &gp_Trsf::ScaleFactor, "Returns the scale factor.");
cls_gp_Trsf.def("TranslationPart", (const gp_XYZ & (gp_Trsf::*)() const) &gp_Trsf::TranslationPart, "Returns the translation part of the transformation's matrix");
cls_gp_Trsf.def("GetRotation", [](gp_Trsf &self, gp_XYZ & theAxis, Standard_Real & theAngle){ Standard_Boolean rv = self.GetRotation(theAxis, theAngle); return std::tuple<Standard_Boolean, Standard_Real &>(rv, theAngle); }, "Returns the boolean True if there is non-zero rotation. In the presence of rotation, the output parameters store the axis and the angle of rotation. The method always returns positive value 'theAngle', i.e., 0. < theAngle <= PI. Note that this rotation is defined only by the vectorial part of the transformation; generally you would need to check also the translational part to obtain the axis (gp_Ax1) of rotation.", py::arg("theAxis"), py::arg("theAngle"));
cls_gp_Trsf.def("GetRotation", (gp_Quaternion (gp_Trsf::*)() const) &gp_Trsf::GetRotation, "Returns quaternion representing rotational part of the transformation.");
cls_gp_Trsf.def("VectorialPart", (gp_Mat (gp_Trsf::*)() const) &gp_Trsf::VectorialPart, "Returns the vectorial part of the transformation. It is a 3*3 matrix which includes the scale factor.");
cls_gp_Trsf.def("HVectorialPart", (const gp_Mat & (gp_Trsf::*)() const) &gp_Trsf::HVectorialPart, "Computes the homogeneous vectorial part of the transformation. It is a 3*3 matrix which doesn't include the scale factor. In other words, the vectorial part of this transformation is equal to its homogeneous vectorial part, multiplied by the scale factor. The coefficients of this matrix must be multiplied by the scale factor to obtain the coefficients of the transformation.");
cls_gp_Trsf.def("Value", (Standard_Real (gp_Trsf::*)(const Standard_Integer, const Standard_Integer) const) &gp_Trsf::Value, "Returns the coefficients of the transformation's matrix. It is a 3 rows * 4 columns matrix. This coefficient includes the scale factor. Raises OutOfRanged if Row < 1 or Row > 3 or Col < 1 or Col > 4", py::arg("Row"), py::arg("Col"));
cls_gp_Trsf.def("Invert", (void (gp_Trsf::*)()) &gp_Trsf::Invert, "None");
cls_gp_Trsf.def("Inverted", (gp_Trsf (gp_Trsf::*)() const) &gp_Trsf::Inverted, "Computes the reverse transformation Raises an exception if the matrix of the transformation is not inversible, it means that the scale factor is lower or equal to Resolution from package gp. Computes the transformation composed with T and <me>. In a C++ implementation you can also write Tcomposed = <me> * T. Example : Trsf T1, T2, Tcomp; ............... Tcomp = T2.Multiplied(T1); // or (Tcomp = T2 * T1) Pnt P1(10.,3.,4.); Pnt P2 = P1.Transformed(Tcomp); //using Tcomp Pnt P3 = P1.Transformed(T1); //using T1 then T2 P3.Transform(T2); // P3 = P2 !!!");
cls_gp_Trsf.def("Multiplied", (gp_Trsf (gp_Trsf::*)(const gp_Trsf &) const) &gp_Trsf::Multiplied, "None", py::arg("T"));
cls_gp_Trsf.def("__mul__", (gp_Trsf (gp_Trsf::*)(const gp_Trsf &) const) &gp_Trsf::operator*, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf.def("Multiply", (void (gp_Trsf::*)(const gp_Trsf &)) &gp_Trsf::Multiply, "Computes the transformation composed with <me> and T. <me> = <me> * T", py::arg("T"));
cls_gp_Trsf.def("__imul__", (void (gp_Trsf::*)(const gp_Trsf &)) &gp_Trsf::operator*=, py::is_operator(), "None", py::arg("T"));
cls_gp_Trsf.def("PreMultiply", (void (gp_Trsf::*)(const gp_Trsf &)) &gp_Trsf::PreMultiply, "Computes the transformation composed with <me> and T. <me> = T * <me>", py::arg("T"));
cls_gp_Trsf.def("Power", (void (gp_Trsf::*)(const Standard_Integer)) &gp_Trsf::Power, "None", py::arg("N"));
cls_gp_Trsf.def("Powered", (gp_Trsf (gp_Trsf::*)(const Standard_Integer) const) &gp_Trsf::Powered, "Computes the following composition of transformations <me> * <me> * .......* <me>, N time. if N = 0 <me> = Identity if N < 0 <me> = <me>.Inverse() *...........* <me>.Inverse().", py::arg("N"));
cls_gp_Trsf.def("Transforms", [](gp_Trsf &self, Standard_Real & X, Standard_Real & Y, Standard_Real & Z){ self.Transforms(X, Y, Z); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &>(X, Y, Z); }, "None", py::arg("X"), py::arg("Y"), py::arg("Z"));
cls_gp_Trsf.def("Transforms", (void (gp_Trsf::*)(gp_XYZ &) const) &gp_Trsf::Transforms, "Transformation of a triplet XYZ with a Trsf", py::arg("Coord"));

// Enums

}