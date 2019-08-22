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
#include <TopoDS_Shape.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <IGESGeom_RuledSurface.hxx>
#include <IGESGeom_SurfaceOfRevolution.hxx>
#include <IGESGeom_TabulatedCylinder.hxx>
#include <IGESGeom_OffsetSurface.hxx>
#include <IGESGeom_TrimmedSurface.hxx>
#include <IGESGeom_BoundedSurface.hxx>
#include <IGESGeom_Plane.hxx>
#include <IGESSolid_PlaneSurface.hxx>
#include <IGESBasic_SingleParent.hxx>
#include <gp_Trsf2d.hxx>
#include <gp_Pln.hxx>
#include <gp_Trsf.hxx>
#include <IGESToBRep_TopoSurface.hxx>

void bind_IGESToBRep_TopoSurface(py::module &mod){

py::class_<IGESToBRep_TopoSurface, IGESToBRep_CurveAndSurface> cls_IGESToBRep_TopoSurface(mod, "IGESToBRep_TopoSurface", "Provides methods to transfer topologic surfaces entities from IGES to CASCADE.");

// Constructors
cls_IGESToBRep_TopoSurface.def(py::init<>());
cls_IGESToBRep_TopoSurface.def(py::init<const IGESToBRep_CurveAndSurface &>(), py::arg("CS"));
cls_IGESToBRep_TopoSurface.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("eps"), py::arg("epsGeom"), py::arg("epsCoeff"), py::arg("mode"), py::arg("modeapprox"), py::arg("optimized"));

// Fields

// Methods
// cls_IGESToBRep_TopoSurface.def_static("operator new_", (void * (*)(size_t)) &IGESToBRep_TopoSurface::operator new, "None", py::arg("theSize"));
// cls_IGESToBRep_TopoSurface.def_static("operator delete_", (void (*)(void *)) &IGESToBRep_TopoSurface::operator delete, "None", py::arg("theAddress"));
// cls_IGESToBRep_TopoSurface.def_static("operator new[]_", (void * (*)(size_t)) &IGESToBRep_TopoSurface::operator new[], "None", py::arg("theSize"));
// cls_IGESToBRep_TopoSurface.def_static("operator delete[]_", (void (*)(void *)) &IGESToBRep_TopoSurface::operator delete[], "None", py::arg("theAddress"));
// cls_IGESToBRep_TopoSurface.def_static("operator new_", (void * (*)(size_t, void *)) &IGESToBRep_TopoSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESToBRep_TopoSurface.def_static("operator delete_", (void (*)(void *, void *)) &IGESToBRep_TopoSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESToBRep_TopoSurface.def("TransferTopoSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoSurface::TransferTopoSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferTopoBasicSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESData_IGESEntity> &)) &IGESToBRep_TopoSurface::TransferTopoBasicSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferRuledSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_RuledSurface> &)) &IGESToBRep_TopoSurface::TransferRuledSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferSurfaceOfRevolution", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_SurfaceOfRevolution> &)) &IGESToBRep_TopoSurface::TransferSurfaceOfRevolution, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferTabulatedCylinder", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_TabulatedCylinder> &)) &IGESToBRep_TopoSurface::TransferTabulatedCylinder, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferOffsetSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_OffsetSurface> &)) &IGESToBRep_TopoSurface::TransferOffsetSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferTrimmedSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_TrimmedSurface> &)) &IGESToBRep_TopoSurface::TransferTrimmedSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferBoundedSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_BoundedSurface> &)) &IGESToBRep_TopoSurface::TransferBoundedSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferPlane", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESGeom_Plane> &)) &IGESToBRep_TopoSurface::TransferPlane, "None", py::arg("start"));
// cls_IGESToBRep_TopoSurface.def("TransferPlaneSurface", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESSolid_PlaneSurface> &)) &IGESToBRep_TopoSurface::TransferPlaneSurface, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("TransferPerforate", (TopoDS_Shape (IGESToBRep_TopoSurface::*)(const opencascade::handle<IGESBasic_SingleParent> &)) &IGESToBRep_TopoSurface::TransferPerforate, "None", py::arg("start"));
cls_IGESToBRep_TopoSurface.def("ParamSurface", [](IGESToBRep_TopoSurface &self, const opencascade::handle<IGESData_IGESEntity> & start, gp_Trsf2d & trans, Standard_Real & uFact){ TopoDS_Shape rv = self.ParamSurface(start, trans, uFact); return std::tuple<TopoDS_Shape, Standard_Real &>(rv, uFact); }, "None", py::arg("start"), py::arg("trans"), py::arg("uFact"));

// Enums

}