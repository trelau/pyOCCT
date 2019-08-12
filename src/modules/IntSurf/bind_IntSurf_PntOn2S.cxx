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
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <gp_Pnt2d.hxx>
#include <IntSurf_PntOn2S.hxx>

void bind_IntSurf_PntOn2S(py::module &mod){

py::class_<IntSurf_PntOn2S, std::unique_ptr<IntSurf_PntOn2S, Deleter<IntSurf_PntOn2S>>> cls_IntSurf_PntOn2S(mod, "IntSurf_PntOn2S", "This class defines the geometric informations for an intersection point between 2 surfaces : The coordinates ( Pnt from gp ), and two parametric coordinates.");

// Constructors
cls_IntSurf_PntOn2S.def(py::init<>());

// Fields

// Methods
// cls_IntSurf_PntOn2S.def_static("operator new_", (void * (*)(size_t)) &IntSurf_PntOn2S::operator new, "None", py::arg("theSize"));
// cls_IntSurf_PntOn2S.def_static("operator delete_", (void (*)(void *)) &IntSurf_PntOn2S::operator delete, "None", py::arg("theAddress"));
// cls_IntSurf_PntOn2S.def_static("operator new[]_", (void * (*)(size_t)) &IntSurf_PntOn2S::operator new[], "None", py::arg("theSize"));
// cls_IntSurf_PntOn2S.def_static("operator delete[]_", (void (*)(void *)) &IntSurf_PntOn2S::operator delete[], "None", py::arg("theAddress"));
// cls_IntSurf_PntOn2S.def_static("operator new_", (void * (*)(size_t, void *)) &IntSurf_PntOn2S::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IntSurf_PntOn2S.def_static("operator delete_", (void (*)(void *, void *)) &IntSurf_PntOn2S::operator delete, "None", py::arg(""), py::arg(""));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &)) &IntSurf_PntOn2S::SetValue, "Sets the value of the point in 3d space.", py::arg("Pt"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &, const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Sets the values of the point in 3d space, and in the parametric space of one of the surface.", py::arg("Pt"), py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const gp_Pnt &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Sets the values of the point in 3d space, and in the parametric space of each surface.", py::arg("Pt"), py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const Standard_Boolean, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Set the values of the point in the parametric space of one of the surface.", py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_PntOn2S.def("SetValue", (void (IntSurf_PntOn2S::*)(const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &IntSurf_PntOn2S::SetValue, "Set the values of the point in the parametric space of one of the surface.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("Value", (const gp_Pnt & (IntSurf_PntOn2S::*)() const) &IntSurf_PntOn2S::Value, "Returns the point in 3d space.");
cls_IntSurf_PntOn2S.def("ValueOnSurface", (gp_Pnt2d (IntSurf_PntOn2S::*)(const Standard_Boolean) const) &IntSurf_PntOn2S::ValueOnSurface, "Returns the point in 2d space of one of the surfaces.", py::arg("OnFirst"));
cls_IntSurf_PntOn2S.def("ParametersOnS1", [](IntSurf_PntOn2S &self, Standard_Real & U1, Standard_Real & V1){ self.ParametersOnS1(U1, V1); return std::tuple<Standard_Real &, Standard_Real &>(U1, V1); }, "Returns the parameters of the point on the first surface.", py::arg("U1"), py::arg("V1"));
cls_IntSurf_PntOn2S.def("ParametersOnS2", [](IntSurf_PntOn2S &self, Standard_Real & U2, Standard_Real & V2){ self.ParametersOnS2(U2, V2); return std::tuple<Standard_Real &, Standard_Real &>(U2, V2); }, "Returns the parameters of the point on the second surface.", py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("ParametersOnSurface", [](IntSurf_PntOn2S &self, const Standard_Boolean OnFirst, Standard_Real & U, Standard_Real & V){ self.ParametersOnSurface(OnFirst, U, V); return std::tuple<Standard_Real &, Standard_Real &>(U, V); }, "Returns the parameters of the point in the parametric space of one of the surface.", py::arg("OnFirst"), py::arg("U"), py::arg("V"));
cls_IntSurf_PntOn2S.def("Parameters", [](IntSurf_PntOn2S &self, Standard_Real & U1, Standard_Real & V1, Standard_Real & U2, Standard_Real & V2){ self.Parameters(U1, V1, U2, V2); return std::tuple<Standard_Real &, Standard_Real &, Standard_Real &, Standard_Real &>(U1, V1, U2, V2); }, "Returns the parameters of the point on both surfaces.", py::arg("U1"), py::arg("V1"), py::arg("U2"), py::arg("V2"));
cls_IntSurf_PntOn2S.def("IsSame", [](IntSurf_PntOn2S &self, const IntSurf_PntOn2S & a0) -> Standard_Boolean { return self.IsSame(a0); });
cls_IntSurf_PntOn2S.def("IsSame", [](IntSurf_PntOn2S &self, const IntSurf_PntOn2S & a0, const Standard_Real a1) -> Standard_Boolean { return self.IsSame(a0, a1); });
cls_IntSurf_PntOn2S.def("IsSame", (Standard_Boolean (IntSurf_PntOn2S::*)(const IntSurf_PntOn2S &, const Standard_Real, const Standard_Real) const) &IntSurf_PntOn2S::IsSame, "Returns TRUE if 2D- and 3D-coordinates of theOterPoint are equal to corresponding coordinates of me (with given tolerance). If theTol2D < 0.0 we will compare 3D-points only.", py::arg("theOtherPoint"), py::arg("theTol3D"), py::arg("theTol2D"));

// Enums

}