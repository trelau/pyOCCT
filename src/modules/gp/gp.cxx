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

void bind_gp_TrsfForm(py::module &);
void bind_gp_EulerSequence(py::module &);
void bind_gp_XY(py::module &);
void bind_gp(py::module &);
void bind_gp_Mat2d(py::module &);
void bind_gp_Pnt2d(py::module &);
void bind_gp_Vec2d(py::module &);
void bind_gp_Dir2d(py::module &);
void bind_gp_Ax2d(py::module &);
void bind_gp_Trsf2d(py::module &);
void bind_gp_Mat(py::module &);
void bind_gp_XYZ(py::module &);
void bind_gp_Trsf(py::module &);
void bind_gp_Vec(py::module &);
void bind_gp_Dir(py::module &);
void bind_gp_Pnt(py::module &);
void bind_gp_VectorWithNullMagnitude(py::module &);
void bind_gp_Lin2d(py::module &);
void bind_gp_Ax22d(py::module &);
void bind_gp_Circ2d(py::module &);
void bind_gp_Elips2d(py::module &);
void bind_gp_Hypr2d(py::module &);
void bind_gp_Parab2d(py::module &);
void bind_gp_Ax1(py::module &);
void bind_gp_Ax2(py::module &);
void bind_gp_Circ(py::module &);
void bind_gp_Lin(py::module &);
void bind_gp_Elips(py::module &);
void bind_gp_Hypr(py::module &);
void bind_gp_Parab(py::module &);
void bind_gp_Ax3(py::module &);
void bind_gp_Pln(py::module &);
void bind_gp_Cylinder(py::module &);
void bind_gp_Cone(py::module &);
void bind_gp_Sphere(py::module &);
void bind_gp_Torus(py::module &);
void bind_gp_GTrsf(py::module &);
void bind_gp_Quaternion(py::module &);
void bind_gp_QuaternionNLerp(py::module &);
void bind_NCollection_Lerp(py::module &);
void bind_gp_TrsfNLerp(py::module &);
void bind_gp_GTrsf2d(py::module &);
void bind_gp_QuaternionSLerp(py::module &);

PYBIND11_MODULE(gp, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.Precision");

bind_gp_TrsfForm(mod);
bind_gp_EulerSequence(mod);
bind_gp_XY(mod);
bind_gp(mod);
bind_gp_Mat2d(mod);
bind_gp_Pnt2d(mod);
bind_gp_Vec2d(mod);
bind_gp_Dir2d(mod);
bind_gp_Ax2d(mod);
bind_gp_Trsf2d(mod);
bind_gp_Mat(mod);
bind_gp_XYZ(mod);
bind_gp_Trsf(mod);
bind_gp_Vec(mod);
bind_gp_Dir(mod);
bind_gp_Pnt(mod);
bind_gp_VectorWithNullMagnitude(mod);
bind_gp_Lin2d(mod);
bind_gp_Ax22d(mod);
bind_gp_Circ2d(mod);
bind_gp_Elips2d(mod);
bind_gp_Hypr2d(mod);
bind_gp_Parab2d(mod);
bind_gp_Ax1(mod);
bind_gp_Ax2(mod);
bind_gp_Circ(mod);
bind_gp_Lin(mod);
bind_gp_Elips(mod);
bind_gp_Hypr(mod);
bind_gp_Parab(mod);
bind_gp_Ax3(mod);
bind_gp_Pln(mod);
bind_gp_Cylinder(mod);
bind_gp_Cone(mod);
bind_gp_Sphere(mod);
bind_gp_Torus(mod);
bind_gp_GTrsf(mod);
bind_gp_Quaternion(mod);
bind_gp_QuaternionNLerp(mod);
bind_NCollection_Lerp(mod);
bind_gp_TrsfNLerp(mod);
bind_gp_GTrsf2d(mod);
bind_gp_QuaternionSLerp(mod);

}
