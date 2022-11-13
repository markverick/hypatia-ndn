#include "satellite-position-helper.h"

#include "ns3/simulator.h"
#include "ns3/nstime.h"

namespace ns3 {

SatellitePositionHelper::SatellitePositionHelper (void)
{
  SetStartTime (JulianDate ());
}

SatellitePositionHelper::SatellitePositionHelper (Ptr<Satellite> sat)
{
  SetSatellite (sat);
  SetStartTime (sat->GetTleEpoch ());
}

SatellitePositionHelper::SatellitePositionHelper(
  Ptr<Satellite> sat, const JulianDate &t
)
{
  SetSatellite (sat);
  SetStartTime (t);
}

Vector3D
SatellitePositionHelper::GetPosition (void) const
{
  if (!m_sat)
    return Vector3D (0,0,0);

  JulianDate cur = m_start + Simulator::Now ();

  return m_sat->GetPosition (cur);
}

Vector3D
SatellitePositionHelper::GetVelocity (void) const
{
  if (!m_sat)
    return Vector3D (0,0,0);

  JulianDate cur = m_start + Simulator::Now ();

  return m_sat->GetVelocity (cur);
}

Ptr<Satellite>
SatellitePositionHelper::GetSatellite (void) const
{
  return m_sat;
}

JulianDate
SatellitePositionHelper::GetStartTime (void) const
{
  return m_start;
}

std::string
SatellitePositionHelper::GetSatelliteName (void) const
{
  return (!m_sat ? m_sat->GetName () : "");
}

void
SatellitePositionHelper::SetSatellite (Ptr<Satellite> sat)
{
  m_sat = sat;
}

void
SatellitePositionHelper::SetStartTime (const JulianDate &t)
{
  m_start = t;
}

}
