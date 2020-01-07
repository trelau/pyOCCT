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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom_Curve.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_Surface.hxx>
#include <Geom_Plane.hxx>
#include <gp_Dir.hxx>
#include <GeomProjLib.hxx>

PYBIND11_MODULE(GeomProjLib, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2d");
py::module::import("OCCT.Geom");
py::module::import("OCCT.gp");

// CLASS: GEOMPROJLIB
py::class_<GeomProjLib> cls_GeomProjLib(mod, "GeomProjLib", "Projection of a curve on a surface.");

// Constructors
cls_GeomProjLib.def(py::init<>());

// Methods
// cls_GeomProjLib.def_static("operator new_", (void * (*)(size_t)) &GeomProjLib::operator new, "None", py::arg("theSize"));
// cls_GeomProjLib.def_static("operator delete_", (void (*)(void *)) &GeomProjLib::operator delete, "None", py::arg("theAddress"));
// cls_GeomProjLib.def_static("operator new[]_", (void * (*)(size_t)) &GeomProjLib::operator new[], "None", py::arg("theSize"));
// cls_GeomProjLib.def_static("operator delete[]_", (void (*)(void *)) &GeomProjLib::operator delete[], "None", py::arg("theAddress"));
// cls_GeomProjLib.def_static("operator new_", (void * (*)(size_t, void *)) &GeomProjLib::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomProjLib.def_static("operator delete_", (void (*)(void *, void *)) &GeomProjLib::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomProjLib.def_static("Curve2d_", [](const opencascade::handle<Geom_Curve> & C, const Standard_Real First, const Standard_Real Last, const opencascade::handle<Geom_Surface> & S, const Standard_Real UFirst, const Standard_Real ULast, const Standard_Real VFirst, const Standard_Real VLast, Standard_Real & Tolerance){ opencascade::handle<Geom2d_Curve> rv = GeomProjLib::Curve2d(C, First, Last, S, UFirst, ULast, VFirst, VLast, Tolerance); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &>(rv, Tolerance); }, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ) The 3dCurve is taken between the parametrization range [First, Last] <Tolerance> is used as input if the projection needs an approximation. In this case, the reached tolerance is set in <Tolerance> as output. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("First"), py::arg("Last"), py::arg("S"), py::arg("UFirst"), py::arg("ULast"), py::arg("VFirst"), py::arg("VLast"), py::arg("Tolerance"));
cls_GeomProjLib.def_static("Curve2d_", [](const opencascade::handle<Geom_Curve> & C, const Standard_Real First, const Standard_Real Last, const opencascade::handle<Geom_Surface> & S, Standard_Real & Tolerance){ opencascade::handle<Geom2d_Curve> rv = GeomProjLib::Curve2d(C, First, Last, S, Tolerance); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &>(rv, Tolerance); }, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ) The 3dCurve is taken between the parametrization range [First, Last] <Tolerance> is used as input if the projection needs an approximation. In this case, the reached tolerance is set in <Tolerance> as output. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("First"), py::arg("Last"), py::arg("S"), py::arg("Tolerance"));
cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ) The 3dCurve is taken between the parametrization range [First, Last] If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("First"), py::arg("Last"), py::arg("S"));
cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ). If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle.", py::arg("C"), py::arg("S"));
cls_GeomProjLib.def_static("Curve2d_", (opencascade::handle<Geom2d_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomProjLib::Curve2d, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ). If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle. can expand a little the bounds of surface", py::arg("C"), py::arg("S"), py::arg("UDeb"), py::arg("UFin"), py::arg("VDeb"), py::arg("VFin"));
cls_GeomProjLib.def_static("Curve2d_", [](const opencascade::handle<Geom_Curve> & C, const opencascade::handle<Geom_Surface> & S, const Standard_Real UDeb, const Standard_Real UFin, const Standard_Real VDeb, const Standard_Real VFin, Standard_Real & Tolerance){ opencascade::handle<Geom2d_Curve> rv = GeomProjLib::Curve2d(C, S, UDeb, UFin, VDeb, VFin, Tolerance); return std::tuple<opencascade::handle<Geom2d_Curve>, Standard_Real &>(rv, Tolerance); }, "gives the 2d-curve of a 3d-curve lying on a surface ( uses GeomProjLib_ProjectedCurve ). If the projection needs an approximation, Precision::PApproximation() is used. WARNING : if the projection has failed, this method returns a null Handle. can expand a little the bounds of surface", py::arg("C"), py::arg("S"), py::arg("UDeb"), py::arg("UFin"), py::arg("VDeb"), py::arg("VFin"), py::arg("Tolerance"));
cls_GeomProjLib.def_static("Project_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Surface> &)) &GeomProjLib::Project, "Constructs the 3d-curve from the normal projection of the Curve <C> on the surface <S>. WARNING : if the projection has failes returns a null Handle.", py::arg("C"), py::arg("S"));
cls_GeomProjLib.def_static("ProjectOnPlane_", (opencascade::handle<Geom_Curve> (*)(const opencascade::handle<Geom_Curve> &, const opencascade::handle<Geom_Plane> &, const gp_Dir &, const Standard_Boolean)) &GeomProjLib::ProjectOnPlane, "Constructs the 3d-curves from the projection of the curve <Curve> on the plane <Plane> along the direction <Dir>. If <KeepParametrization> is true, the parametrization of the Projected Curve <PC> will be the same as the parametrization of the initial curve <C>. It meens: proj(C(u)) = PC(u) for each u. Otherwize, the parametrization may change.", py::arg("Curve"), py::arg("Plane"), py::arg("Dir"), py::arg("KeepParametrization"));


}
