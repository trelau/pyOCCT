/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <GeomToIGES_GeomEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom_Curve.hxx>
#include <Geom_BoundedCurve.hxx>
#include <Geom_BSplineCurve.hxx>
#include <Geom_BezierCurve.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Conic.hxx>
#include <Geom_Circle.hxx>
#include <Geom_Ellipse.hxx>
#include <Geom_Hyperbola.hxx>
#include <Geom_Line.hxx>
#include <Geom_Parabola.hxx>
#include <Geom_OffsetCurve.hxx>
#include <GeomToIGES_GeomCurve.hxx>
#include <IGESGeom_Point.hxx>
#include <Geom_Point.hxx>
#include <Geom_CartesianPoint.hxx>
#include <GeomToIGES_GeomPoint.hxx>
#include <Geom_Surface.hxx>
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
#include <IGESGeom_Direction.hxx>
#include <Geom_Vector.hxx>
#include <Geom_VectorWithMagnitude.hxx>
#include <Geom_Direction.hxx>
#include <GeomToIGES_GeomVector.hxx>

PYBIND11_MODULE(GeomToIGES, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IGESData");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.IGESGeom");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomToIGES_GeomEntity.hxx
	py::class_<GeomToIGES_GeomEntity, std::unique_ptr<GeomToIGES_GeomEntity, Deleter<GeomToIGES_GeomEntity>>> cls_GeomToIGES_GeomEntity(mod, "GeomToIGES_GeomEntity", "provides methods to transfer Geom entity from CASCADE to IGES.");
	cls_GeomToIGES_GeomEntity.def(py::init<>());
	cls_GeomToIGES_GeomEntity.def(py::init([] (const GeomToIGES_GeomEntity &other) {return new GeomToIGES_GeomEntity(other);}), "Copy constructor", py::arg("other"));
	cls_GeomToIGES_GeomEntity.def("SetModel", (void (GeomToIGES_GeomEntity::*)(const opencascade::handle<IGESData_IGESModel> &)) &GeomToIGES_GeomEntity::SetModel, "Set the value of 'TheModel'", py::arg("model"));
	cls_GeomToIGES_GeomEntity.def("GetModel", (opencascade::handle<IGESData_IGESModel> (GeomToIGES_GeomEntity::*)() const ) &GeomToIGES_GeomEntity::GetModel, "Returns the value of 'TheModel'");
	cls_GeomToIGES_GeomEntity.def("SetUnit", (void (GeomToIGES_GeomEntity::*)(const Standard_Real)) &GeomToIGES_GeomEntity::SetUnit, "Sets the value of the UnitFlag", py::arg("unit"));
	cls_GeomToIGES_GeomEntity.def("GetUnit", (Standard_Real (GeomToIGES_GeomEntity::*)() const ) &GeomToIGES_GeomEntity::GetUnit, "Returns the value of the UnitFlag of the header of the model in meters.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomToIGES_GeomCurve.hxx
	py::class_<GeomToIGES_GeomCurve, std::unique_ptr<GeomToIGES_GeomCurve, Deleter<GeomToIGES_GeomCurve>>, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomCurve(mod, "GeomToIGES_GeomCurve", "This class implements the transfer of the Curve Entity from Geom To IGES. These can be : Curve . BoundedCurve * BSplineCurve * BezierCurve * TrimmedCurve . Conic * Circle * Ellipse * Hyperbloa * Line * Parabola . OffsetCurve");
	cls_GeomToIGES_GeomCurve.def(py::init<>());
	cls_GeomToIGES_GeomCurve.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Curve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomCurve(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_BoundedCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_BSplineCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_BezierCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_TrimmedCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Conic> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Circle> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Ellipse> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Hyperbola> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Line> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_Parabola> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));
	cls_GeomToIGES_GeomCurve.def("TransferCurve", (opencascade::handle<IGESData_IGESEntity> (GeomToIGES_GeomCurve::*)(const opencascade::handle<Geom_OffsetCurve> &, const Standard_Real, const Standard_Real)) &GeomToIGES_GeomCurve::TransferCurve, "None", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomToIGES_GeomPoint.hxx
	py::class_<GeomToIGES_GeomPoint, std::unique_ptr<GeomToIGES_GeomPoint, Deleter<GeomToIGES_GeomPoint>>, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomPoint(mod, "GeomToIGES_GeomPoint", "This class implements the transfer of the Point Entity from Geom to IGES . These are : . Point * CartesianPoint");
	cls_GeomToIGES_GeomPoint.def(py::init<>());
	cls_GeomToIGES_GeomPoint.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));
	cls_GeomToIGES_GeomPoint.def("TransferPoint", (opencascade::handle<IGESGeom_Point> (GeomToIGES_GeomPoint::*)(const opencascade::handle<Geom_Point> &)) &GeomToIGES_GeomPoint::TransferPoint, "Transfert a Point from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
	cls_GeomToIGES_GeomPoint.def("TransferPoint", (opencascade::handle<IGESGeom_Point> (GeomToIGES_GeomPoint::*)(const opencascade::handle<Geom_CartesianPoint> &)) &GeomToIGES_GeomPoint::TransferPoint, "Transfert a CartesianPoint from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomToIGES_GeomSurface.hxx
	py::class_<GeomToIGES_GeomSurface, std::unique_ptr<GeomToIGES_GeomSurface, Deleter<GeomToIGES_GeomSurface>>, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomSurface(mod, "GeomToIGES_GeomSurface", "This class implements the transfer of the Surface Entity from Geom To IGES. These can be : . BoundedSurface * BSplineSurface * BezierSurface * RectangularTrimmedSurface . ElementarySurface * Plane * CylindricalSurface * ConicalSurface * SphericalSurface * ToroidalSurface . SweptSurface * SurfaceOfLinearExtrusion * SurfaceOfRevolution . OffsetSurface");
	cls_GeomToIGES_GeomSurface.def(py::init<>());
	cls_GeomToIGES_GeomSurface.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));
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
	cls_GeomToIGES_GeomSurface.def("Length", (Standard_Real (GeomToIGES_GeomSurface::*)() const ) &GeomToIGES_GeomSurface::Length, "Returns the value of 'TheLength'");
	cls_GeomToIGES_GeomSurface.def("GetBRepMode", (Standard_Boolean (GeomToIGES_GeomSurface::*)() const ) &GeomToIGES_GeomSurface::GetBRepMode, "Returns Brep mode flag.");
	cls_GeomToIGES_GeomSurface.def("SetBRepMode", (void (GeomToIGES_GeomSurface::*)(const Standard_Boolean)) &GeomToIGES_GeomSurface::SetBRepMode, "Sets BRep mode flag.", py::arg("flag"));
	cls_GeomToIGES_GeomSurface.def("GetAnalyticMode", (Standard_Boolean (GeomToIGES_GeomSurface::*)() const ) &GeomToIGES_GeomSurface::GetAnalyticMode, "Returns flag for writing elementary surfaces");
	cls_GeomToIGES_GeomSurface.def("SetAnalyticMode", (void (GeomToIGES_GeomSurface::*)(const Standard_Boolean)) &GeomToIGES_GeomSurface::SetAnalyticMode, "Setst flag for writing elementary surfaces", py::arg("flag"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\GeomToIGES_GeomVector.hxx
	py::class_<GeomToIGES_GeomVector, std::unique_ptr<GeomToIGES_GeomVector, Deleter<GeomToIGES_GeomVector>>, GeomToIGES_GeomEntity> cls_GeomToIGES_GeomVector(mod, "GeomToIGES_GeomVector", "This class implements the transfer of the Vector from Geom to IGES . These can be : . Vector * Direction * VectorWithMagnitude");
	cls_GeomToIGES_GeomVector.def(py::init<>());
	cls_GeomToIGES_GeomVector.def(py::init<const GeomToIGES_GeomEntity &>(), py::arg("GE"));
	cls_GeomToIGES_GeomVector.def("TransferVector", (opencascade::handle<IGESGeom_Direction> (GeomToIGES_GeomVector::*)(const opencascade::handle<Geom_Vector> &)) &GeomToIGES_GeomVector::TransferVector, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomVector(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
	cls_GeomToIGES_GeomVector.def("TransferVector", (opencascade::handle<IGESGeom_Direction> (GeomToIGES_GeomVector::*)(const opencascade::handle<Geom_VectorWithMagnitude> &)) &GeomToIGES_GeomVector::TransferVector, "None", py::arg("start"));
	cls_GeomToIGES_GeomVector.def("TransferVector", (opencascade::handle<IGESGeom_Direction> (GeomToIGES_GeomVector::*)(const opencascade::handle<Geom_Direction> &)) &GeomToIGES_GeomVector::TransferVector, "None", py::arg("start"));


}
