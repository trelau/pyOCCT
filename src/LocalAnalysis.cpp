#include <pyOCCT_Common.hpp>

#include <Standard_Handle.hxx>
#include <Geom_Surface.hxx>
#include <Standard_TypeDef.hxx>
#include <GeomAbs_Shape.hxx>
#include <Geom2d_Curve.hxx>
#include <GeomLProp_SLProps.hxx>
#include <LocalAnalysis_StatusErrorType.hxx>
#include <LocalAnalysis_SurfaceContinuity.hxx>
#include <Geom_Curve.hxx>
#include <LocalAnalysis_CurveContinuity.hxx>
#include <Standard_OStream.hxx>
#include <LocalAnalysis.hxx>

PYBIND11_MODULE(LocalAnalysis, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.Geom");
	py::module::import("OCCT.GeomAbs");
	py::module::import("OCCT.Geom2d");
	py::module::import("OCCT.GeomLProp");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS
	// C:\Miniconda\envs\occt\Library\include\opencascade\LocalAnalysis_StatusErrorType.hxx
	py::enum_<LocalAnalysis_StatusErrorType>(mod, "LocalAnalysis_StatusErrorType", "None")
		.value("LocalAnalysis_NullFirstDerivative", LocalAnalysis_StatusErrorType::LocalAnalysis_NullFirstDerivative)
		.value("LocalAnalysis_NullSecondDerivative", LocalAnalysis_StatusErrorType::LocalAnalysis_NullSecondDerivative)
		.value("LocalAnalysis_TangentNotDefined", LocalAnalysis_StatusErrorType::LocalAnalysis_TangentNotDefined)
		.value("LocalAnalysis_NormalNotDefined", LocalAnalysis_StatusErrorType::LocalAnalysis_NormalNotDefined)
		.value("LocalAnalysis_CurvatureNotDefined", LocalAnalysis_StatusErrorType::LocalAnalysis_CurvatureNotDefined)
		.export_values();

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\LocalAnalysis_SurfaceContinuity.hxx
	py::class_<LocalAnalysis_SurfaceContinuity, std::unique_ptr<LocalAnalysis_SurfaceContinuity, Deleter<LocalAnalysis_SurfaceContinuity>>> cls_LocalAnalysis_SurfaceContinuity(mod, "LocalAnalysis_SurfaceContinuity", "This class gives tools to check local continuity C0 C1 C2 G1 G2 between two points situated on two surfaces");
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const opencascade::handle<Geom_Surface> &, const Standard_Real, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Surf1"), py::arg("u1"), py::arg("v1"), py::arg("Surf2"), py::arg("u2"), py::arg("v2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"), py::arg("Maxlen"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const opencascade::handle<Geom2d_Curve> &, const opencascade::handle<Geom2d_Curve> &, const Standard_Real, const opencascade::handle<Geom_Surface> &, const opencascade::handle<Geom_Surface> &, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("curv1"), py::arg("curv2"), py::arg("U"), py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"), py::arg("Maxlen"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<>());
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real>(), py::arg("EpsNul"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"));
	cls_LocalAnalysis_SurfaceContinuity.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("Percent"), py::arg("Maxlen"));
	cls_LocalAnalysis_SurfaceContinuity.def("ComputeAnalysis", (void (LocalAnalysis_SurfaceContinuity::*)(GeomLProp_SLProps &, GeomLProp_SLProps &, const GeomAbs_Shape)) &LocalAnalysis_SurfaceContinuity::ComputeAnalysis, "None", py::arg("Surf1"), py::arg("Surf2"), py::arg("Order"));
	cls_LocalAnalysis_SurfaceContinuity.def("IsDone", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::IsDone, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("ContinuityStatus", (GeomAbs_Shape (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::ContinuityStatus, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("StatusError", (LocalAnalysis_StatusErrorType (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::StatusError, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C0Value", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C0Value, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C1UAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C1UAngle, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C1URatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C1URatio, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C1VAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C1VAngle, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C1VRatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C1VRatio, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C2UAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C2UAngle, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C2URatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C2URatio, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C2VAngle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C2VAngle, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("C2VRatio", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::C2VRatio, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("G1Angle", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::G1Angle, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("G2CurvatureGap", (Standard_Real (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::G2CurvatureGap, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("IsC0", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::IsC0, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("IsC1", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::IsC1, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("IsC2", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::IsC2, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("IsG1", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::IsG1, "None");
	cls_LocalAnalysis_SurfaceContinuity.def("IsG2", (Standard_Boolean (LocalAnalysis_SurfaceContinuity::*)() const ) &LocalAnalysis_SurfaceContinuity::IsG2, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocalAnalysis_CurveContinuity.hxx
	py::class_<LocalAnalysis_CurveContinuity, std::unique_ptr<LocalAnalysis_CurveContinuity, Deleter<LocalAnalysis_CurveContinuity>>> cls_LocalAnalysis_CurveContinuity(mod, "LocalAnalysis_CurveContinuity", "This class gives tools to check local continuity C0 C1 C2 G1 G2 between two points situated on two curves");
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("EpsG2"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("EpsG2"), py::arg("Percent"));
	cls_LocalAnalysis_CurveContinuity.def(py::init<const opencascade::handle<Geom_Curve> &, const Standard_Real, const opencascade::handle<Geom_Curve> &, const Standard_Real, const GeomAbs_Shape, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Curv1"), py::arg("u1"), py::arg("Curv2"), py::arg("u2"), py::arg("Order"), py::arg("EpsNul"), py::arg("EpsC0"), py::arg("EpsC1"), py::arg("EpsC2"), py::arg("EpsG1"), py::arg("EpsG2"), py::arg("Percent"), py::arg("Maxlen"));
	cls_LocalAnalysis_CurveContinuity.def("IsDone", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::IsDone, "None");
	cls_LocalAnalysis_CurveContinuity.def("StatusError", (LocalAnalysis_StatusErrorType (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::StatusError, "None");
	cls_LocalAnalysis_CurveContinuity.def("ContinuityStatus", (GeomAbs_Shape (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::ContinuityStatus, "None");
	cls_LocalAnalysis_CurveContinuity.def("C0Value", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::C0Value, "None");
	cls_LocalAnalysis_CurveContinuity.def("C1Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::C1Angle, "None");
	cls_LocalAnalysis_CurveContinuity.def("C1Ratio", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::C1Ratio, "None");
	cls_LocalAnalysis_CurveContinuity.def("C2Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::C2Angle, "None");
	cls_LocalAnalysis_CurveContinuity.def("C2Ratio", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::C2Ratio, "None");
	cls_LocalAnalysis_CurveContinuity.def("G1Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::G1Angle, "None");
	cls_LocalAnalysis_CurveContinuity.def("G2Angle", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::G2Angle, "None");
	cls_LocalAnalysis_CurveContinuity.def("G2CurvatureVariation", (Standard_Real (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::G2CurvatureVariation, "None");
	cls_LocalAnalysis_CurveContinuity.def("IsC0", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::IsC0, "None");
	cls_LocalAnalysis_CurveContinuity.def("IsC1", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::IsC1, "None");
	cls_LocalAnalysis_CurveContinuity.def("IsC2", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::IsC2, "None");
	cls_LocalAnalysis_CurveContinuity.def("IsG1", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::IsG1, "None");
	cls_LocalAnalysis_CurveContinuity.def("IsG2", (Standard_Boolean (LocalAnalysis_CurveContinuity::*)() const ) &LocalAnalysis_CurveContinuity::IsG2, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\LocalAnalysis.hxx
	py::class_<LocalAnalysis, std::unique_ptr<LocalAnalysis, Deleter<LocalAnalysis>>> cls_LocalAnalysis(mod, "LocalAnalysis", "This package gives tools to check the local continuity between two points situated on two curves or two surfaces.");
	cls_LocalAnalysis.def(py::init<>());
	// FIXME cls_LocalAnalysis.def_static("Dump_", (void (*)(const LocalAnalysis_SurfaceContinuity &, Standard_OStream &)) &LocalAnalysis::Dump, "This class compute s and gives tools to check the local continuity between two points situated on 2 curves)", py::arg("surfconti"), py::arg("o"));
	// FIXME cls_LocalAnalysis.def_static("Dump_", (void (*)(const LocalAnalysis_CurveContinuity &, Standard_OStream &)) &LocalAnalysis::Dump, "This fonction gives informations about a variable SurfaceContinuity", py::arg("curvconti"), py::arg("o"));


}
