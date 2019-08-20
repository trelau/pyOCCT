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
#include <GeomToIGES_GeomEntity.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <Geom_BoundedSurface.hxx>
#include <Geom_BSplineSurface.hxx>
#include <Geom_BezierSurface.hxx>
#include <Geom_RectangularTrimmedSurface.hxx>
#include <Geom_ElementarySurface.hxx>
#include <Geom_Plane.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_ConicalSurface.hxx>
#include <Geom_SphericalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Geom_SweptSurface.hxx>
#include <Geom_SurfaceOfLinearExtrusion.hxx>
#include <Geom_SurfaceOfRevolution.hxx>
#include <Geom_OffsetSurface.hxx>
#include <GeomToIGES_GeomSurface.hxx>

void bind_GeomToIGES_GeomSurface(py::module &mod){

py::class_<GeomToIGES_GeomSurface, std::unique_ptr<GeomToIGES_GeomSurface>, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomSurface(mod, "GeomToIGES_GeomSurface", "This class implements the transfer of the Surface Entity from Geom To IGES. These can be : . BoundedSurface * BSplineSurface * BezierSurface * RectangularTrimmedSurface . ElementarySurface * Plane * CylindricalSurface * ConicalSurface * SphericalSurface * ToroidalSurface . SweptSurface * SurfaceOfLinearExtrusion * SurfaceOfRevolution . OffsetSurface");

// Constructors
cls_GeomToIGES_GeomSurface.def(py::init<>());
cls_GeomToIGES_GeomSurface.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));

// Fields

// Methods
// cls_GeomToIGES_GeomSurface.def_static("operator new_", (void * (*)(size_t)) &GeomToIGES_GeomSurface::operator new, "None", py::arg("theSize"));
// cls_GeomToIGES_GeomSurface.def_static("operator delete_", (void (*)(void *)) &GeomToIGES_GeomSurface::operator delete, "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomSurface.def_static("operator new[]_", (void * (*)(size_t)) &GeomToIGES_GeomSurface::operator new[], "None", py::arg("theSize"));
// cls_GeomToIGES_GeomSurface.def_static("operator delete[]_", (void (*)(void *)) &GeomToIGES_GeomSurface::operator delete[], "None", py::arg("theAddress"));
// cls_GeomToIGES_GeomSurface.def_static("operator new_", (void * (*)(size_t, void *)) &GeomToIGES_GeomSurface::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_GeomToIGES_GeomSurface.def_static("operator delete_", (void (*)(void *, void *)) &GeomToIGES_GeomSurface::operator delete, "None", py::arg(""), py::arg(""));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomSurface(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_BoundedSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_BSplineSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_BezierSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_RectangularTrimmedSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_ElementarySurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_Plane> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_CylindricalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_ConicalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_SphericalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_ToroidalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_SweptSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_SurfaceOfLinearExtrusion> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_SurfaceOfRevolution> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_OffsetSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferPlaneSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_Plane> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferPlaneSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferCylindricalSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_CylindricalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferCylindricalSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferConicalSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_ConicalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferConicalSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferSphericalSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_SphericalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferSphericalSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("TransferToroidalSurface", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomSurface::*)(const opencascade::handle<Geom_ToroidalSurface> &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomSurface::TransferToroidalSurface, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"), py::arg("Vdeb"), py::arg("Vfin"));
cls_GeomToIGES_GeomSurface.def("Length", (Standard_Real (GeomToIGES_GeomSurface::*)() const) &GeomToIGES_GeomSurface::Length, "Returns the value of 'TheLength'");
cls_GeomToIGES_GeomSurface.def("GetBRepMode", (Standard_Boolean (GeomToIGES_GeomSurface::*)() const) &GeomToIGES_GeomSurface::GetBRepMode, "Returns Brep mode flag.");
cls_GeomToIGES_GeomSurface.def("SetBRepMode", (void (GeomToIGES_GeomSurface::*)(const Standard_Boolean)) &GeomToIGES_GeomSurface::SetBRepMode, "Sets BRep mode flag.", py::arg("flag"));
cls_GeomToIGES_GeomSurface.def("GetAnalyticMode", (Standard_Boolean (GeomToIGES_GeomSurface::*)() const) &GeomToIGES_GeomSurface::GetAnalyticMode, "Returns flag for writing elementary surfaces");
cls_GeomToIGES_GeomSurface.def("SetAnalyticMode", (void (GeomToIGES_GeomSurface::*)(const Standard_Boolean)) &GeomToIGES_GeomSurface::SetAnalyticMode, "Setst flag for writing elementary surfaces", py::arg("flag"));

// Enums

}