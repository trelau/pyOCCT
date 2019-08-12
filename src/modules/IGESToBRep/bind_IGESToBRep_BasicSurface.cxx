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
#include <IGESToBRep_CurveAndSurface.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom_Plane.hxx>
#include <IGESSolid_PlaneSurface.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <IGESSolid_CylindricalSurface.hxx>
#include <Geom_ConicalSurface.hxx>
#include <IGESSolid_ConicalSurface.hxx>
#include <Geom_SphericalSurface.hxx>
#include <IGESSolid_SphericalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <IGESSolid_ToroidalSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <IGESGeom_SplineSurface.hxx>
#include <IGESGeom_BSplineSurface.hxx>
#include <IGESToBRep_BasicSurface.hxx>

void bind_IGESToBRep_BasicSurface(py::module &mod){

py::class_<IGESToBRep_BasicSurface, std::unique_ptr<IGESToBRep_BasicSurface, Deleter<IGESToBRep_BasicSurface>>, IGESToBRep_CurveAndSurface> cls_IGESToBRep_BasicSurface(mod, "IGESToBRep_BasicSurface", "Provides methods to transfer basic geometric surface entities from IGES to CASCADE. These can be : * Spline surface * BSpline surface");

// Constructors
cls_IGESToBRep_BasicSurface.def(py::init<>());
cls_IGESToBRep_BasicSurface.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
cls_IGESToBRep_BasicSurface.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));

// Fields

// Methods
// cls_IGESToBRep_BasicSurface.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep_BasicSurface::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep_BasicSurface.def_static("operator delete_", (void (*)(void *)) &IGESToBRep_BasicSurface::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep_BasicSurface.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep_BasicSurface::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep_BasicSurface.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep_BasicSurface::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep_BasicSurface.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep_BasicSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep_BasicSurface.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep_BasicSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep_BasicSurface.def("TransferBasicSurface", (opencascade::handle<Geom_Surface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_BasicSurface::TransferBasicSurface, "Returns Surface from Geom if the last transfer has succeded.", py::arg("start"));
cls_IGESToBRep_BasicSurface.def("TransferPlaneSurface", (opencascade::handle<Geom_Plane> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &)) &IGESToBRep_BasicSurface::TransferPlaneSurface, "Returns Plane from Geom if the transfer has succeded.", py::arg("start"));
cls_IGESToBRep_BasicSurface.def("TransferRigthCylindricalSurface", (opencascade::handle<Geom_CylindricalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_CylindricalSurface> &)) &IGESToBRep_BasicSurface::TransferRigthCylindricalSurface, "Returns CylindricalSurface from Geom if the transfer has succeded.", py::arg("start"));
cls_IGESToBRep_BasicSurface.def("TransferRigthConicalSurface", (opencascade::handle<Geom_ConicalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_ConicalSurface> &)) &IGESToBRep_BasicSurface::TransferRigthConicalSurface, "Returns ConicalSurface from Geom if the transfer has succeded.", py::arg("start"));
cls_IGESToBRep_BasicSurface.def("TransferSphericalSurface", (opencascade::handle<Geom_SphericalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_SphericalSurface> &)) &IGESToBRep_BasicSurface::TransferSphericalSurface, "Returns SphericalSurface from Geom if the transfer has succeded.", py::arg("start"));
cls_IGESToBRep_BasicSurface.def("TransferToroidalSurface", (opencascade::handle<Geom_ToroidalSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESSolid_ToroidalSurface> &)) &IGESToBRep_BasicSurface::TransferToroidalSurface, "Returns SphericalSurface from Geom if the transfer has succeded.", py::arg("start"));
cls_IGESToBRep_BasicSurface.def("TransferSplineSurface", (opencascade::handle<Geom_BSplineSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESGeom_SplineSurface> &)) &IGESToBRep_BasicSurface::TransferSplineSurface, "Returns BSplineSurface from Geom if the transfer has succeded.", py::arg("start"));
cls_IGESToBRep_BasicSurface.def("TransferBSplineSurface", (opencascade::handle<Geom_BSplineSurface> (IGESToBRep_BasicSurface::*)(const opencascade::handle<IGESGeom_BSplineSurface> &)) &IGESToBRep_BasicSurface::TransferBSplineSurface, "Returns BSplineSurface from Geom if the transfer has succeded.", py::arg("start"));

// Enums

}