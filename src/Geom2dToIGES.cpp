#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
PYBIND11_DECLARE_HOLDER_TYPE(T, T*);
using opencascade::handle;

// Deleter template for mixed holder types with public/hidden destructors.
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#include <Geom2dToIGES_Geom2dEntity.hxx>
#include <Standard_Handle.hxx>
#include <IGESData_IGESModel.hxx>
#include <Standard_TypeDef.hxx>
#include <IGESData_IGESEntity.hxx>
#include <Geom2d_Curve.hxx>
#include <Geom2dToIGES_Geom2dCurve.hxx>
#include <IGESGeom_Point.hxx>
#include <Geom2d_Point.hxx>
#include <Geom2d_CartesianPoint.hxx>
#include <Geom2dToIGES_Geom2dPoint.hxx>
#include <IGESGeom_Direction.hxx>
#include <Geom2d_Vector.hxx>
#include <Geom2d_VectorWithMagnitude.hxx>
#include <Geom2d_Direction.hxx>
#include <Geom2dToIGES_Geom2dVector.hxx>

PYBIND11_MODULE(Geom2dToIGES, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.IGESData");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.IGESGeom");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dToIGES_Geom2dEntity.hxx
	py::class_<Geom2dToIGES_Geom2dEntity, std::unique_ptr<Geom2dToIGES_Geom2dEntity, Deleter<Geom2dToIGES_Geom2dEntity>>> cls_Geom2dToIGES_Geom2dEntity(mod, "Geom2dToIGES_Geom2dEntity", "provides methods to transfer Geom2d entity from CASCADE to IGES.");
	cls_Geom2dToIGES_Geom2dEntity.def(py::init<>());
	cls_Geom2dToIGES_Geom2dEntity.def(py::init([] (const Geom2dToIGES_Geom2dEntity &other) {return new Geom2dToIGES_Geom2dEntity(other);}), "Copy constructor", py::arg("other"));
	cls_Geom2dToIGES_Geom2dEntity.def("SetModel", (void (Geom2dToIGES_Geom2dEntity::*)(const opencascade::handle<IGESData_IGESModel> &)) &Geom2dToIGES_Geom2dEntity::SetModel, "Set the value of 'TheModel'", py::arg("model"));
	cls_Geom2dToIGES_Geom2dEntity.def("GetModel", (opencascade::handle<IGESData_IGESModel> (Geom2dToIGES_Geom2dEntity::*)() const ) &Geom2dToIGES_Geom2dEntity::GetModel, "Returns the value of 'TheModel'");
	cls_Geom2dToIGES_Geom2dEntity.def("SetUnit", (void (Geom2dToIGES_Geom2dEntity::*)(const Standard_Real)) &Geom2dToIGES_Geom2dEntity::SetUnit, "Sets the value of the UnitFlag", py::arg("unit"));
	cls_Geom2dToIGES_Geom2dEntity.def("GetUnit", (Standard_Real (Geom2dToIGES_Geom2dEntity::*)() const ) &Geom2dToIGES_Geom2dEntity::GetUnit, "Returns the value of the UnitFlag of the header of the model in millimeters.");

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dToIGES_Geom2dCurve.hxx
	py::class_<Geom2dToIGES_Geom2dCurve, std::unique_ptr<Geom2dToIGES_Geom2dCurve, Deleter<Geom2dToIGES_Geom2dCurve>>, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dCurve(mod, "Geom2dToIGES_Geom2dCurve", "This class implements the transfer of the Curve Entity from Geom2d To IGES. These can be : Curve . BoundedCurve * BSplineCurve * BezierCurve * TrimmedCurve . Conic * Circle * Ellipse * Hyperbloa * Line * Parabola . OffsetCurve");
	cls_Geom2dToIGES_Geom2dCurve.def(py::init<>());
	cls_Geom2dToIGES_Geom2dCurve.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));
	cls_Geom2dToIGES_Geom2dCurve.def("Transfer2dCurve", (opencascade::handle<IGESData_IGESEntity> (Geom2dToIGES_Geom2dCurve::*)(const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const Standard_Real)) &Geom2dToIGES_Geom2dCurve::Transfer2dCurve, "Transfert an Entity from Geom2d to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"), py::arg("Udeb"), py::arg("Ufin"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dToIGES_Geom2dPoint.hxx
	py::class_<Geom2dToIGES_Geom2dPoint, std::unique_ptr<Geom2dToIGES_Geom2dPoint, Deleter<Geom2dToIGES_Geom2dPoint>>, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dPoint(mod, "Geom2dToIGES_Geom2dPoint", "This class implements the transfer of the Point Entity from Geom2d to IGES . These are : . 2dPoint * 2dCartesianPoint");
	cls_Geom2dToIGES_Geom2dPoint.def(py::init<>());
	cls_Geom2dToIGES_Geom2dPoint.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));
	cls_Geom2dToIGES_Geom2dPoint.def("Transfer2dPoint", (opencascade::handle<IGESGeom_Point> (Geom2dToIGES_Geom2dPoint::*)(const opencascade::handle<Geom2d_Point> &)) &Geom2dToIGES_Geom2dPoint::Transfer2dPoint, "Transfert a Point from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
	cls_Geom2dToIGES_Geom2dPoint.def("Transfer2dPoint", (opencascade::handle<IGESGeom_Point> (Geom2dToIGES_Geom2dPoint::*)(const opencascade::handle<Geom2d_CartesianPoint> &)) &Geom2dToIGES_Geom2dPoint::Transfer2dPoint, "Transfert a CartesianPoint from Geom to IGES. If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\Geom2dToIGES_Geom2dVector.hxx
	py::class_<Geom2dToIGES_Geom2dVector, std::unique_ptr<Geom2dToIGES_Geom2dVector, Deleter<Geom2dToIGES_Geom2dVector>>, Geom2dToIGES_Geom2dEntity> cls_Geom2dToIGES_Geom2dVector(mod, "Geom2dToIGES_Geom2dVector", "This class implements the transfer of the Vector from Geom2d to IGES . These can be : . Vector * Direction * VectorWithMagnitude");
	cls_Geom2dToIGES_Geom2dVector.def(py::init<>());
	cls_Geom2dToIGES_Geom2dVector.def(py::init<const Geom2dToIGES_Geom2dEntity &>(), py::arg("G2dE"));
	cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_Vector> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "Transfert a GeometryEntity which answer True to the member : BRepToIGES::IsGeomVector(Geometry). If this Entity could not be converted, this member returns a NullEntity.", py::arg("start"));
	cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_VectorWithMagnitude> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "None", py::arg("start"));
	cls_Geom2dToIGES_Geom2dVector.def("Transfer2dVector", (opencascade::handle<IGESGeom_Direction> (Geom2dToIGES_Geom2dVector::*)(const opencascade::handle<Geom2d_Direction> &)) &Geom2dToIGES_Geom2dVector::Transfer2dVector, "None", py::arg("start"));


}
