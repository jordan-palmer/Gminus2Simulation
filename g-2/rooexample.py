#!/usr/bin/python                                                                                                                               

from ROOT import *

gSystem.Load("RooJordan2_cxx.so")

#variables
t = RooRealVar("t", "time", 0., 30.e-6)
wa = RooRealVar("wa", "wa", 2.975e+6)
A = RooRealVar("A", "A",0.2)
phi = RooRealVar("phi", "phi", 0.01)
N = RooRealVar("N", "N", 10.e+8)
tau = RooRealVar("tau", "tau", 2.2e-6)

#fitter variables
fwa = RooRealVar("fwa", "fwa", 1.1e+6, 0., 10.0e+6)
fA = RooRealVar("fA","fA",0.2, 0., 10.0)
fphi = RooRealVar("fphi","fphi",0.01,0.,10.0)
fN = RooRealVar("fN","fphi",10.0e+8,0.,20.0e+8)
ftau = RooRealVar("ftau","ftau",2.2e-6,0.,1.0e-6)

pdf = RooJordan2("pdf","pdf",t, wa, A, tau, phi, N)
fpdf = RooJordan2("fpdf" ,"fpdf", t, fwa,fA,ftau,fphi,fN)
data = pdf.generate(RooArgSet(t), 1000000)

fpdf.fitTo(data)

frame = t.frame()

data.plotOn(frame)
fpdf.plotOn(frame)
frame.Draw()

raw_input ("Press Enter..")
